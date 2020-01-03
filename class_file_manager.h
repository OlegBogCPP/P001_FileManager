#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <chrono>
#include <utility>

namespace fs = std::filesystem;

class FileManagerMy {
public:
    FileManagerMy(std::string const & pathResultFile) {
        output.open(pathResultFile);
    }
    void PrintDir(std::string& pathDir);
private:
    void PermsOut(fs::perms p);
    void FileType(const fs::path& path);
    std::ofstream output;
};
