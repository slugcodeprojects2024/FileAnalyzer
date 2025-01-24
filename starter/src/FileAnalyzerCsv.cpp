#include "FileAnalyzerCsv.h"
#include <sstream>

FileAnalyzerCsv::FileAnalyzerCsv(const std::string& filename)
    : FileAnalyzerFile(filename, allowed_extensions) {}

const std::vector<std::string> FileAnalyzerCsv::allowed_extensions = {".csv"};

size_t FileAnalyzerCsv::columns() const {
    std::istringstream stream(std::string(contents_.get(), file_size_));
    std::string line;
    if (std::getline(stream, line)) {
        size_t count = 1;
        for (char c : line) {
            if (c == ',') count++;
        }
        return count;
    }
    return 0;
}

size_t FileAnalyzerCsv::rows() const {
    std::istringstream stream(std::string(contents_.get(), file_size_));
    std::string line;
    size_t count = 0;
    while (std::getline(stream, line)) {
        if (!line.empty()) {
            count++;
        }
    }
    return count;
}

bool FileAnalyzerCsv::verifyDimensions() const {
    size_t expected_columns = columns();
    std::istringstream stream(std::string(contents_.get(), file_size_));
    std::string line;
    while (std::getline(stream, line)) {
        if (line.empty()) continue;
        size_t count = 1;
        for (char c : line) {
            if (c == ',') count++;
        }
        if (count != expected_columns) return false;
    }
    return true;
}