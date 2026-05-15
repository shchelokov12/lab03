# Лабораторная работа №03
## Изучение систем автоматизации сборки проекта на примере CMake
Судент: Щелоков Александр ИУ8-25

GitHub: shchelokov12

Gmail: aesch8877@gmail.com

## Ход работы
### 1. Подготовка окружения
1) Создан публичный репозиторий `lab03` на GitHub
2) Настроена рабочая директория
3) Установлены необходимые инструменты (CMake, tree)

### 2. Ручная сборка проекта (без CMake)
#### Компиляция библиотеки print:
```
$ g++ -std=c++11 -I./include -c sources/print.cpp
$ ar rvs print.a print.o
```
#### Сборка example1
```
$ g++ -std=c++11 -I./include -c examples/example1.cpp
$ g++ example1.o print.a -o example1
$ ./example1
hello
```
#### Сборка example2
```
$ g++ -std=c++11 -I./include -c examples/example2.cpp
$ g++ example2.o print.a -o example2
$ ./example2
$ cat log.txt
hello
```

### 3. Автоматизация сборки с CMake
Создан CMakeLists.txt следующего содержания:
```
cmake_minimum_required(VERSION 3.4)
project(print)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(print STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(example1 ${CMAKE_CURRENT_SOURCE_DIR}/examples/example1.cpp)
add_executable(example2 ${CMAKE_CURRENT_SOURCE_DIR}/examples/example2.cpp)

target_link_libraries(example1 print)
target_link_libraries(example2 print)
```
Конфигурация и сборка:
```
$ cmake -H. -B_build
$ cmake --build _build
```
Установка проекта:
```
$ cmake --build _build --target install -DCMAKE_INSTALL_PREFIX=_install
```
Структура после установки:
```
_install/
├── include
│   └── print.hpp
└── lib
    └── libprint.a
```

### 4. Проверка собранных примеров
```
$ _build/example1
hello
$ _build/example2
$ cat log.txt
hello
```

## Вывод
В ходе лабораторной работы я изучил систему автоматизации сборки CMake, освоив переход от ручной компиляции с g++ к автоматизированной сборке проекта с созданием статической библиотеки и исполняемых файлов.
