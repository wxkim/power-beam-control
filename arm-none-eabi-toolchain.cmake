# Target system settings for ARM Cortex-M (cross-compiling)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Specify the cross-compiler
set(CMAKE_C_COMPILER /opt/homebrew/bin/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER /opt/homebrew/bin/arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER /opt/homebrew/bin/arm-none-eabi-gcc)

# Prevent CMake from passing macOS-specific flags (like -arch)
set(CMAKE_C_FLAGS "")
set(CMAKE_CXX_FLAGS "")
