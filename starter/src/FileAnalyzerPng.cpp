// Copyright (c) 2025 Ethan Sifferman.
// All rights reserved. Distribution Prohibited.

#include "src/FileAnalyzerPng.h"

#include <fstream>
#include <iostream>

FileAnalyzerPng::FileAnalyzerPng(const std::string& filename)
    : FileAnalyzerFile(filename, allowed_extensions) {}

const std::vector<std::string> FileAnalyzerPng::allowed_extensions = {".png"};

uint32_t FileAnalyzerPng::width() const {
  return ReadBigEndianInt32(contents_.get() + 0x10);
}

uint32_t FileAnalyzerPng::height() const {
  return ReadBigEndianInt32(contents_.get() + 0x14);
}
