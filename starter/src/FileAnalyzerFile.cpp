// Copyright (c) 2025 Ethan Sifferman.
// All rights reserved. Distribution Prohibited.

#include "src/FileAnalyzerFile.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

FileAnalyzerFile::FileAnalyzerFile(
    const std::string& filename,
    const std::vector<std::string>& allowed_extensions)
    : filename_(filename) {
  bool valid_extension = false;
  for (const auto& extension : allowed_extensions) {
    valid_extension |= hasExtension(filename, extension);
  }
  if (!valid_extension) {
    std::cerr << "Unsupported file extension." << std::endl;
    exit(0);
  }
  LoadFile(filename);
}

void FileAnalyzerFile::LoadFile(const std::string& filename) {
  std::ifstream file(filename, std::ios::binary | std::ios::ate);
  if (!file) {
    throw std::runtime_error("Could not open file: " + filename);
  }
  file_size_ = file.tellg();
  contents_ = std::make_unique<char[]>(file_size_);
  file.seekg(0, std::ios::beg);
  file.read(contents_.get(), file_size_);
}

size_t FileAnalyzerFile::file_size() const {
  return file_size_;
}

bool FileAnalyzerFile::hasExtension(const std::string& filename,
                                    const std::string& extension) const {
  return (filename.size() >= extension.size()) &&
         (filename.compare(filename.size() - extension.size(), extension.size(),
                           extension) == 0);
}

int32_t FileAnalyzerFile::ReadLittleEndianInt32(const char* buffer) {
  return static_cast<int32_t>(static_cast<unsigned char>(buffer[0])) |
         (static_cast<int32_t>(static_cast<unsigned char>(buffer[1])) << 8) |
         (static_cast<int32_t>(static_cast<unsigned char>(buffer[2])) << 16) |
         (static_cast<int32_t>(static_cast<unsigned char>(buffer[3])) << 24);
}

int16_t FileAnalyzerFile::ReadLittleEndianInt16(const char* buffer) {
  return static_cast<int16_t>(static_cast<unsigned char>(buffer[0])) |
         (static_cast<int16_t>(static_cast<unsigned char>(buffer[1])) << 8);
}

int32_t FileAnalyzerFile::ReadBigEndianInt32(const char* buffer) {
  return (static_cast<int32_t>(static_cast<unsigned char>(buffer[0])) << 24) |
         (static_cast<int32_t>(static_cast<unsigned char>(buffer[1])) << 16) |
         (static_cast<int32_t>(static_cast<unsigned char>(buffer[2])) << 8) |
         static_cast<int32_t>(static_cast<unsigned char>(buffer[3]));
}