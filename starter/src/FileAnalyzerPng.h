#pragma once

#include "FileAnalyzerFile.h"

class FileAnalyzerPng : public FileAnalyzerFile {
 public:
  FileAnalyzerPng(const std::string& filename);
  uint32_t width() const;
  uint32_t height() const;
  static const std::vector<std::string> allowed_extensions;
};
