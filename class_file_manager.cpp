#include "class_file_manager.h"

void FileManagerMy::PermsOut(fs::perms p) {
    output << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
           << ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
           << ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
           << ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
           << ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
           << ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
           << ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
           << ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
           << ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-");
}

void FileManagerMy::FileType(const fs::path& path) {
    if(fs::is_regular_file(path)) {
        output << "-";
    }
    if(fs::is_directory(path)) {
        output << "d";
    }
    if(fs::is_block_file(path)) {
        output << "b";
    }
    if(fs::is_character_file(path)) {
        output << "c";
    }
    if(fs::is_fifo(path)) {
        output << "p";
    }
    if(fs::is_socket(path)) {
        output << "s";
    }
    if(fs::is_symlink(path)) {
        output << "l";
    }
}

void FileManagerMy::PrintDir(std::string& pathDir) {
    output << "\"File name/Dir name\",\" Size (for file)\",Extension,\"Access right\",\"Last modified time\"\n";
    for (auto pP : fs::directory_iterator(pathDir)) {
        output << pP.path().filename() << ",";
        if (fs :: is_directory ( pP.path())) {
            output << "-,dir,";
        } else {
            output << std::filesystem::file_size(pP.path()) << "," << pP.path().extension() << ",";
        }
        FileType(pP.path());
        PermsOut(fs::status(pP.path().filename()).permissions());
        output << "," ;
        fs::path p = pP.path();
        auto ftime = fs::last_write_time(p);
        std::time_t cftime = decltype(ftime)::clock::to_time_t(ftime);
        output << std::asctime(std::localtime(&cftime)) ;//<< '\n'
    }
}
