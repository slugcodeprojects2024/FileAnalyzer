#pragma once

#include "FileAnalyzerFile.h"

class FileAnalyzerWav : public FileAnalyzerFile {
 public:
  FileAnalyzerWav(const std::string& filename);
  uint32_t bitrate() const;
  uint16_t channels() const;
  static const std::vector<std::string> allowed_extensions;
};