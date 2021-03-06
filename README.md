## Описание

На основании заданного абсолютного пути директории в файл `dir_list.csv` выводится содержание (состав) указанной
 директории.

Выводятся следующие атрибуты:
* **File name/Dir name**
* **Size (for file)**
* **Extension**
* **Access right**
* **Last modified time**
## Установка
Сохранить файлы с кодом в директорию (например, `/Users/username/Documents/Exmp/`).

С помощью компилятора (или IDE) создать исполняемый файл (например, `file_exe`).
## Использование
Запуск программы на исполнение осуществляется через Терминал.
 
Запуск исполняемого файла можно осуществить двумя способами:
* перейти в Терминале в директорию, в которой сохранен исполняемы файл, тогда указывается относительный путь к файлу
 (относительно текущей директории)
```zsh
user@MacBook~ % ./file_exe
```
* находясь в Терминале в любой директории, указать абсолютный путь к файлу
```zsh
user@MacBook~ % /Users/username/Documents/Exmp/file_exe
```
Не зависимо от способа указания пути к исполняемому файлу, в качестве аргументов файла должны быть переданы:
* абсолютный путь директории, содержание которой необходимо вывести в результирующий файл (путь указывается в `" "`);
* (`не обязательный аргумент`) полное имя файла, куда будет выводиться содержание заданной директории (по умолчанию - без указания второго аргумента результат будет сохранен в `/Users/nameuser/dir_list.csv`). Путь к файлу указывается в `" "`.

**Примеры:**
```zsh
user@MacBook~ % ./file_exe "/Users/username/Documents/"
```

```zsh
user@MacBook~ % /Users/username/Documents/Exmp/file_exe "/Users/username/Documents/" "/Users/username/Documents/Exmp/result.csv"
```
В случае не указания после исполняемого файла `ни одного` аргумента будет выведено сообщение об ошибке.
```zsh
user@MacBook~ % /Users/username/Documents/Exmp/file_exe 
Ошибка: не указана директория.
Для получения справки введите в Терминале имя исполняемого файла и "--help" в следующем формате:
 <file_exe> --help
```

Если в качестве первого аргумента передать "--help" (без кавычек), то будет выведена краткая справка по использованию программы.
```zsh
user@MacBook~ % /Users/username/Documents/Exmp/file_exe --help
Для запуска программы необходимо ввести в Терминал имя исполняемого файла и аргумент программы в виде абсолютного пути директории.
Формат ввода (путь обязательно указывать в " "):
<file_exe> "/Users/username/Documents/"
По умолчанию (без указания второго аргумента - пути файла результата) результат сохраняется в /Users/username/dir_list.csv
```


