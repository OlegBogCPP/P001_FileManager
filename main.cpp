#include "class_file_manager.h"

std::string DirFileResult(std::string pathResultFile);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Ошибка: не указана директория.\n"
                     "Для получения справки введите в Терминале имя исполняемого файла и \"--help\" в следующем "
                     "формате:\n"
                     " <file_exe> --help\n";
        return 1;
    }
    std::string pathDir = argv[1];
    if (pathDir == "--help") {
        std::cout << "Для запуска программы необходимо ввести в Терминал имя исполняемого файла"
                     " и аргумент программы в виде абсолютного пути директории.\n"
                     "Формат ввода (путь обязательно указывать в \" \"):\n"
                     "<file_exe> \"/Users/username/Documents/\"\n"
                     "По умолчанию (без указания второго аргумента - пути файла результата) результат сохраняется в /Users/username/dir_list.csv\n";
        return 1;
    }
    if(!fs::exists(pathDir)) {
        std::cout << "Ошибка: введенный абсолютный путь директории не существует.\n"
                     "Введите корректный абсолютный путь директории и повторите запуск программы.";
        return 1;
    }
    std::string pathResultFile;
    std::string temp;
    if (argc == 3) {
        pathResultFile = argv[2];
        temp = std::move(DirFileResult(pathResultFile));
        if (!fs::exists(temp)) {
            std::cout << "Ошибка: введенный абсолютный путь файла результата не существует.\n"
                         "Введите корректный абсолютный путь файла и повторите запуск программы\n"
                         "или вызовете справку по программе <file_exe> --help\n";
            return 1;
        }
    } else {
        pathResultFile = "dir_list.csv";
    }
    FileManagerMy dirObj(pathResultFile);
    dirObj.PrintDir(pathDir);
    return 0;
}

std::string DirFileResult(std::string pathResultFile) {
    int cnt = 0;
    for (auto itr = pathResultFile.rbegin(); itr != pathResultFile.rend(); ++itr) {
        if (*itr != '/') {
            ++cnt;
        } else {
            break;
        }
    }
    pathResultFile.resize(pathResultFile.size() - cnt);
    return std::move(pathResultFile);
}
