# Long-Arithmetics

C++ big-integer (long arithmetic) library with a small app and a GoogleTest test suite, built with CMake.

## Project Layout

- `LongArithmeticLib/` — library sources (`longarithmetic.h/.cpp`)
- `App/` — example app entry point
- `Tests/` — GoogleTest-based unit tests

## Prerequisites

- CMake
- A C++ compiler toolchain
  - Windows: Visual Studio (MSBuild) is recommended

## Configure & Build

From the repo root:

### Windows (Visual Studio generator)

```powershell
cmake -S . -B build
cmake --build build --config Debug
```

### Other platforms (Ninja/Makefiles)

```sh
cmake -S . -B build
cmake --build build
```

## Run Tests

Tests are driven through CTest.

```powershell
cd build
ctest -C Debug --output-on-failure
```

(If you build a different configuration, adjust `-C Debug` accordingly.)

## Notes

- Some environments may print a build-time warning like `pwsh.exe is not recognized` during a post-build step. This does not affect the build artifacts or test execution.
