#pragma once

#include "src/FileAnalyzerFile.h"

class FileAnalyzerCsv : public FileAnalyzerFile {
 public:
  FileAnalyzerCsv(const std::string& filename);
  size_t rows() const;
  size_t columns() const;
  bool verifyDimensions() const;
  static const std::vector<std::string> allowed_extensions;
};