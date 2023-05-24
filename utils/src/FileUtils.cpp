//
// Created by golov on 19.05.2023.
//

#include <fstream>
#include <filesystem>
#include "../include/FileUtils.h"

std::wifstream utils::openFileIStream(const std::filesystem::path& file, const std::ios_base::openmode& mode) {
    std::wifstream ifs(file, mode);
    ifs.imbue(std::locale(std::locale::classic(), new std::codecvt_utf8<wchar_t>()));
    return ifs;
}

std::wstring utils::readFile(const std::string& filename) {
    std::filesystem::path file(filename);
    if (!exists(file)) {
        throw std::runtime_error("No file");
    }
    std::wifstream ifs = openFileIStream(file, std::ios::in);
    std::wstring content((std::istreambuf_iterator<wchar_t>(ifs)), (std::istreambuf_iterator<wchar_t>()));
    return content;
}

std::wstring utils::to_wstring(const std::string& string) {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.from_bytes(string);
}

std::string utils::to_string(const std::wstring& wstring) {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.to_bytes(wstring);
}
