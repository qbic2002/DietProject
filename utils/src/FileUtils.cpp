//
// Created by golov on 19.05.2023.
//

#include <fstream>
#include <filesystem>
#include "../include/FileUtils.h"

std::ifstream utils::openFileIStream(const std::filesystem::path& file, const std::ios_base::openmode& mode) {
    std::ifstream ifs(file, mode);
    return ifs;
}

std::string utils::readFile(const std::string& filename) {
    std::filesystem::path file(filename);
    if (!exists(file)) {
        throw std::runtime_error("No file");
    }
    std::ifstream ifs = openFileIStream(file, std::ios::in);
    std::string content((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
    return content;
}
