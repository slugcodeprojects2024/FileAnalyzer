#pragma once

#include "src/FileAnalyzerFile.h"
#include <unordered_map>
#include <vector>
#include <string>

class FileAnalyzerText : public FileAnalyzerFile {
 public:
  FileAnalyzerText(const std::string& filename);
  std::unordered_map<char, size_t> letterCount() const;
  std::vector<std::pair<char, size_t>> letterCountSorted() const;
  std::string mostCommonWord() const;
  std::string leastCommonWord() const;
  static const std::vector<std::string> allowed_extensions;
};