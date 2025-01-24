#include "FileAnalyzerCode.h"
#include <stack>
#include <sstream>
#include <algorithm>
#include <cctype>

FileAnalyzerCode::FileAnalyzerCode(const std::string& filename)
    : FileAnalyzerFile(filename, allowed_extensions) {}

const std::vector<std::string> FileAnalyzerCode::allowed_extensions = {".c", ".cpp", ".h"};

size_t FileAnalyzerCode::getLines() const {
    std::istringstream stream(std::string(contents_.get(), file_size_));
    std::string line;
    size_t count = 0;
    while (std::getline(stream, line)) {
        if (!line.empty() && line.find_first_not_of(" \t\r\n") != std::string::npos) {
            count++;
        }
    }
    return count;
}

bool FileAnalyzerCode::checkParens() const {
  std::stack<char> stack;
  for (size_t i = 0; i < file_size_; ++i) {
    char c = contents_[i];
    if (c == '(' || c == '{' || c == '[') {
      stack.push(c);
    } else if (c == ')' || c == '}' || c == ']') {
      if (stack.empty()) return false;
      char open = stack.top();
      stack.pop();
      if ((c == ')' && open != '(') || (c == '}' && open != '{') || (c == ']' && open != '[')) {
        return false;
      }
    }
  }
  return stack.empty();
}