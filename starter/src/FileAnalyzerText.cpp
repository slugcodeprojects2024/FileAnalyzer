#include "FileAnalyzerText.h"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <unordered_map>
#include <vector>

FileAnalyzerText::FileAnalyzerText(const std::string& filename)
    : FileAnalyzerFile(filename, allowed_extensions) {}

const std::vector<std::string> FileAnalyzerText::allowed_extensions = {".txt"};

std::unordered_map<char, size_t> FileAnalyzerText::letterCount() const {
    std::unordered_map<char, size_t> count;
    // Initialize all letters with zero counts
    for (char c = 'a'; c <= 'z'; c++) {
        count[c] = 0;
    }
    // Count actual occurrences
    for (size_t i = 0; i < file_size_; ++i) {
        char c = std::tolower(contents_[i]);
        if (std::isalpha(c)) {
            count[c]++;
        }
    }
    return count;
}

std::vector<std::pair<char, size_t>> FileAnalyzerText::letterCountSorted() const {
    std::vector<std::pair<char, size_t>> sorted_count;
    auto count = letterCount();
    // Create vector in alphabetical order
    for (char c = 'a'; c <= 'z'; c++) {
        sorted_count.emplace_back(c, count[c]);
    }
    // Sort by count descending, then alphabetically
    std::sort(sorted_count.begin(), sorted_count.end(),
              [](const auto& a, const auto& b) {
                  return (a.second > b.second) || 
                         (a.second == b.second && a.first < b.first);
              });
    return sorted_count;
}

std::string FileAnalyzerText::mostCommonWord() const {
  std::unordered_map<std::string, size_t> word_count;
  std::istringstream stream(contents_.get());
  std::string word;
  while (stream >> word) {
    word_count[word]++;
  }
  if (word_count.empty()) return "";
  auto max_it = std::max_element(word_count.begin(), word_count.end(),
                                [](const auto& a, const auto& b) {
                                  return a.second < b.second;
                                });
  return max_it->first;
}

std::string FileAnalyzerText::leastCommonWord() const {
  std::unordered_map<std::string, size_t> word_count;
  std::istringstream stream(contents_.get());
  std::string word;
  while (stream >> word) {
    word_count[word]++;
  }
  if (word_count.empty()) return "";
  auto min_it = std::min_element(word_count.begin(), word_count.end(),
                                [](const auto& a, const auto& b) {
                                  return a.second < b.second;
                                });
  return min_it->first;
}