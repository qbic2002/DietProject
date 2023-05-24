

#include <string>
#include <filesystem>

#ifndef DIETPROJECT_FILEUTILS_H
#define DIETPROJECT_FILEUTILS_H

#endif //DIETPROJECT_FILEUTILS_H

namespace utils {
    std::wstring readFile(const std::string& filename); // чтеие файла
    std::wifstream openFileIStream(const std::filesystem::path& file, const std::ios_base::openmode& mode); // открытие файлового потока

    std::wstring to_wstring(const std::string& string); // string to wstring чтобы были русские буквы
    std::string to_string(const std::wstring& wstring); // wstring to string чтобы работала библиотека json
}