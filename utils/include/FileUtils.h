//
// Created by golov on 19.05.2023.
//

#include <string>
#include <filesystem>

#ifndef DIETPROJECT_FILEUTILS_H
#define DIETPROJECT_FILEUTILS_H

#endif //DIETPROJECT_FILEUTILS_H

namespace utils {
    std::wstring readFile(const std::string& filename);
    std::wifstream openFileIStream(const std::filesystem::path& file, const std::ios_base::openmode& mode);

    std::wstring to_wstring(const std::string& string);
    std::string to_string(const std::wstring& wstring);
}