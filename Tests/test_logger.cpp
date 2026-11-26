#include <gtest/gtest.h>
#include "Logger.h"

#include <string>
#include <string_view>

TEST(LoggerTest, FormatsPrintfArguments)
{
    constexpr std::string_view formatWithSuffix = "count=%d state=%s%% ignored";
    const auto format = formatWithSuffix.substr(0, formatWithSuffix.find(" ignored"));

    ::testing::internal::CaptureStderr();
    LOG_INFO(0, "result=%d", 42);
    LOG_WARN(7, format, 3, "ready");
    const auto output = ::testing::internal::GetCapturedStderr();

    EXPECT_NE(output.find("[INF][module=0] result=42"), std::string::npos);
    EXPECT_NE(output.find("[WRN][module=7] count=3 state=ready%"), std::string::npos);
    EXPECT_EQ(output.find(" ignored"), std::string::npos);
}

TEST(LoggerTest, LogsTextWithoutArguments)
{
    ::testing::internal::CaptureStderr();
    LOG_INFO(0, "progress: 100%");
    const auto output = ::testing::internal::GetCapturedStderr();

    EXPECT_NE(output.find("[INF][module=0] progress: 100%"), std::string::npos);
}
