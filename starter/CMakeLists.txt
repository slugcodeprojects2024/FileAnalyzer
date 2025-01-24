# Copyright (c) 2025 Ethan Sifferman.
# All rights reserved. Distribution Prohibited.

cmake_minimum_required(VERSION 3.14)

project(FileAnalyzer)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

# Add executable
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/FileAnalyzerFile.cpp
    src/FileAnalyzerPng.cpp
    src/FileAnalyzerWav.cpp
    src/FileAnalyzerCsv.cpp
    src/FileAnalyzerText.cpp
    src/FileAnalyzerCode.cpp
)

include(FetchContent)
FetchContent_Declare(
    cli11_proj
    QUIET
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.4.1
)

FetchContent_MakeAvailable(cli11_proj)

target_link_libraries(${PROJECT_NAME} PRIVATE CLI11::CLI11)
