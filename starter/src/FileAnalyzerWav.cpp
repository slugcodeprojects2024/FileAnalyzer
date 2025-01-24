#include "src/FileAnalyzerWav.h"

FileAnalyzerWav::FileAnalyzerWav(const std::string& filename)
    : FileAnalyzerFile(filename, allowed_extensions) {}

const std::vector<std::string> FileAnalyzerWav::allowed_extensions = {".wav"};

uint32_t FileAnalyzerWav::bitrate() const {
  return ReadLittleEndianInt32(contents_.get() + 0x1C) * 8;
}

uint16_t FileAnalyzerWav::channels() const {
  return ReadLittleEndianInt16(contents_.get() + 0x16);
}