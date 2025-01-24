#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "CLI/CLI.hpp"
#include "FileAnalyzer.h"
#include "FileAnalyzerWav.h"
#include "FileAnalyzerCsv.h"
#include "FileAnalyzerText.h"
#include "FileAnalyzerCode.h"
#include "FileAnalyzerPng.h"

int main(int argc, char* argv[]) {
    std::string filename;
    bool get_size = false;
    bool png_get_width = false;
    bool png_get_height = false;
    bool csv_get_rows = false;
    bool csv_get_columns = false;
    bool csv_verify_dimensions = false;
    bool wav_get_bitrate = false;
    bool wav_get_channels = false;
    bool code_get_lines = false;
    bool code_check_parens = false;
    bool text_get_letter_count = false;
    bool text_get_letter_count_sorted = false;
    bool text_get_most_common = false;
    bool text_get_least_common = false;

    CLI::App app{"FileAnalyzer"};
    app.add_option("filename", filename, "Input file")->required();
    app.add_flag("--get-size", get_size);
    app.add_flag("--png-get-width", png_get_width);
    app.add_flag("--png-get-height", png_get_height);
    app.add_flag("--csv-get-rows", csv_get_rows);
    app.add_flag("--csv-get-columns", csv_get_columns);
    app.add_flag("--csv-verify-dimensions", csv_verify_dimensions);
    app.add_flag("--wav-get-bitrate", wav_get_bitrate);
    app.add_flag("--wav-get-channels", wav_get_channels);
    app.add_flag("--code-get-lines", code_get_lines);
    app.add_flag("--code-check-parens", code_check_parens);
    app.add_flag("--text-get-letter-count", text_get_letter_count);
    app.add_flag("--text-get-letter-count-sorted", text_get_letter_count_sorted);
    app.add_flag("--text-get-most-common", text_get_most_common);
    app.add_flag("--text-get-least-common", text_get_least_common);

    CLI11_PARSE(app, argc, argv);

    // Get file extension
    size_t dot_pos = filename.rfind('.');
    if (dot_pos == std::string::npos) {
        std::cout << "Unsupported file extension." << std::endl;
        return 1;
    }
    std::string ext = filename.substr(dot_pos + 1);

    std::vector<std::string> wav_exts = {".wav"};
    std::vector<std::string> csv_exts = {".csv"};
    std::vector<std::string> txt_exts = {".txt"};
    std::vector<std::string> code_exts = {".c", ".cpp", ".h"};
    std::vector<std::string> png_exts = {".png"};

    if (get_size) {
        if (ext == "wav") {
            FileAnalyzerWav file(filename);
            std::cout << file.getSize() << std::endl;
        } else if (ext == "csv") {
            FileAnalyzerCsv file(filename);
            std::cout << file.getSize() << std::endl;
        } else if (ext == "txt") {
            FileAnalyzerText file(filename);
            std::cout << file.getSize() << std::endl;
        } else if (ext == "c" || ext == "cpp" || ext == "h") {
            FileAnalyzerCode file(filename);
            std::cout << file.getSize() << std::endl;
        } else if (ext == "png") {
            FileAnalyzerPng file(filename);
            std::cout << file.getSize() << std::endl;
        } else {
            std::cout << "Unsupported file extension." << std::endl;
            return 1;
        }
        return 0;
    }

    if (ext == "wav") {
        FileAnalyzerWav wav(filename);
        if (wav_get_bitrate) wav.getBitrate();
        if (wav_get_channels) wav.getChannels();
    } else if (ext == "csv") {
        FileAnalyzerCsv csv(filename);
        if (csv_get_rows) csv.getRows();
        if (csv_get_columns) csv.getColumns();
        if (csv_verify_dimensions) csv.verifyDimensions();
    } else if (ext == "txt") {
        FileAnalyzerText text(filename);
        if (text_get_letter_count) text.letterCount();
        if (text_get_letter_count_sorted) text.letterCountSorted();
        if (text_get_most_common) text.getMostCommon();
        if (text_get_least_common) text.getLeastCommon();
    } else if (ext == "c" || ext == "cpp" || ext == "h") {
        FileAnalyzerCode code(filename);
        if (code_get_lines) code.getLines();
        if (code_check_parens) code.checkParens();
    } else if (ext == "png") {
        FileAnalyzerPng png(filename);
        if (png_get_width) png.getWidth();
        if (png_get_height) png.getHeight();
    } else {
        std::cout << "Unsupported file extension." << std::endl;
        return 1;
    }

    return 0;
}