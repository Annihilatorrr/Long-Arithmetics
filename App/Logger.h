#pragma once

#include <cstdint>
#include <chrono>
#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <string_view>

namespace logger
{

    enum class LogLevel
    {
        Trace,
        Debug,
        Info,
        Notice,
        Warning,
        Error,
        Critical,
    };

    enum class LogDestination
    {
        StdErr,
        StdOut,
        File,
        Syslog,
    };

    namespace details
    {
        inline std::atomic<LogLevel> g_minLevel{LogLevel::Trace};

        constexpr bool shouldLog(LogLevel msgLevel, LogLevel minLevel)
        {
            return static_cast<int>(msgLevel) >= static_cast<int>(minLevel);
        }

        inline std::string nowTimestampUtc()
        {
            using clock = std::chrono::system_clock;
            const auto now = clock::now();
            const auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
            const std::time_t tt = clock::to_time_t(now);

            std::tm tm{};
#if defined(_WIN32)
            gmtime_s(&tm, &tt);
#else
            gmtime_r(&tt, &tm);
#endif

            std::ostringstream oss;
            oss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S")
                << '.' << std::setw(3) << std::setfill('0') << ms.count()
                << 'Z';
            return oss.str();
        }

        inline const char *levelToString(LogLevel lvl)
        {
            switch (lvl)
            {
            case LogLevel::Trace:
                return "TRC";
            case LogLevel::Debug:
                return "DBG";
            case LogLevel::Info:
                return "INF";
            case LogLevel::Notice:
                return "NTC";
            case LogLevel::Warning:
                return "WRN";
            case LogLevel::Error:
                return "ERR";
            case LogLevel::Critical:
                return "CRT";
            default:
                return "UNK";
            }
        }

        template <typename Module, typename... Args>
        inline void log(LogLevel level, Module module, std::string_view fmt, Args &&...args)
        {
            if (!shouldLog(level, g_minLevel.load(std::memory_order_relaxed)))
            {
                return;
            }

            ((void)args, ...);

            std::fprintf(stderr,
                         "[%s][%s][module=%d] %.*s\n",
                         nowTimestampUtc().c_str(),
                         levelToString(level),
                         static_cast<int>(module),
                         static_cast<int>(fmt.size()),
                         fmt.data());
        }

    } // namespace details

    inline void setGlobalLogLevel(LogLevel level)
    {
        details::g_minLevel.store(level, std::memory_order_relaxed);
    }

} // namespace logger

#define LOG_TRACE(moduleId, fmtStr, ...) ::logger::details::log(::logger::LogLevel::Trace, moduleId, fmtStr __VA_OPT__(, ) __VA_ARGS__)
#define LOG_DEBUG(moduleId, fmtStr, ...) ::logger::details::log(::logger::LogLevel::Debug, moduleId, fmtStr __VA_OPT__(, ) __VA_ARGS__)
#define LOG_INFO(moduleId, fmtStr, ...) ::logger::details::log(::logger::LogLevel::Info, moduleId, fmtStr __VA_OPT__(, ) __VA_ARGS__)
#define LOG_WARN(moduleId, fmtStr, ...) ::logger::details::log(::logger::LogLevel::Warning, moduleId, fmtStr __VA_OPT__(, ) __VA_ARGS__)
#define LOG_ERROR(moduleId, fmtStr, ...) ::logger::details::log(::logger::LogLevel::Error, moduleId, fmtStr __VA_OPT__(, ) __VA_ARGS__)