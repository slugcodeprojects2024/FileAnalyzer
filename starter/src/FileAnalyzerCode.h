#pragma once

#include "src/FileAnalyzerFile.h"

class FileAnalyzerCode : public FileAnalyzerFile {
 public:
  FileAnalyzerCode(const std::string& filename);
  size_t getLines() const;
  bool checkParens() const;
  static const std::vector<std::string> allowed_extensions;
};