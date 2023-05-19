//
// Created by golov on 19.05.2023.
//

#include <string>
#include <filesystem>

#ifndef DIETPROJECT_FILEUTILS_H
#define DIETPROJECT_FILEUTILS_H

#endif //DIETPROJECT_FILEUTILS_H

namespace utils {
    std::string readFile(const std::string& filename);
    std::ifstream openFileIStream(const std::filesystem::path& file, const std::ios_base::openmode& mode);
}