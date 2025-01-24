// Copyright (c) 2025 Ethan Sifferman.
// All rights reserved. Distribution Prohibited.

#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class FileAnalyzerFile {
 public:
  FileAnalyzerFile(const std::string& filename, const std::vector<std::string>& allowed_extensions);
  virtual ~FileAnalyzerFile() = default;

  size_t file_size() const;
  static int32_t ReadLittleEndianInt32(const char* buffer);
  static int16_t ReadLittleEndianInt16(const char* buffer);
  static int32_t ReadBigEndianInt32(const char* buffer);

 protected:
  std::unique_ptr<char[]> contents_;
  size_t file_size_;

 private:
  std::string filename_;
  void LoadFile(const std::string& filename);
  bool hasExtension(const std::string& filename, const std::string& extension) const;
};
