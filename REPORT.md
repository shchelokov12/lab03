# Лабораторная работа №02
## Работа с Git, GitHub и системой контроля версий
Студент: Щелоков Александр

GitHub: shchelokov12

Gmail: aesch8877@gmail.com

## Цель работы
Изучить основы работы с системой контроля версий Git, научиться создавать и настраивать репозитории, выполнять коммиты, отправлять изменения в удалённый репозиторий.

## Ход работы
### 1. Настройка переменных окружения
```
$ export GITHUB_USERNAME=shchelokov12
$ export GITHUB_EMAIL=aesch8877@gmail.com
$ export GITHUB_TOKEN=
$ alias edit=nano
```
### 2. Создание файла конфигурации для автоматической аутентификации
```
$ mkdir ~/.config
$ cat > ~/.config/hub <<EOF
github.com:
- user: ${GITHUB_USERNAME}
  oauth_token: ${GITHUB_TOKEN}
  protocol: https
EOF
$ git config --global hub.protocol https
```
### 3. Создание локального репозитория
Создаем папку проекта, инициализириуем git, задаем имя пользвоателя и почту для комммитов, добавляем удаленный репозиторий
```
$ mkdir projects/lab02 && cd projects/lab02
$ git init
$ git config --global user.name ${GITHUB_USERNAME}
$ git config --global user.email ${GITHUB_EMAIL}
$ git config -e --global
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab02.git
```
### 4. Первый коммит
Получаем изменения из GitHub, создаем README.md, делаем коммит и отправляем изменения
```
$ git pull origin main
$ touch README.md
$ git status
$ git add README.md
$ git commit -m"added README.md"
$ git push origin main
```
### 5. Создание структуры проекта
```
$ mkdir sources
$ mkdir include
$ mkdir examples
```
Файл sources/print.cpp:
```
$ cat > include/print.hpp <<EOF
#include <fstream>
#include <iostream>
#include <string>

void print(const std::string& text, std::ofstream& out);
void print(const std::string& text, std::ostream& out = std::cout);
EOF
```
Файл include/print.hpp:
```
$ cat > include/print.hpp <<EOF
#include <fstream>
#include <iostream>
#include <string>

void print(const std::string& text, std::ofstream& out);
void print(const std::string& text, std::ostream& out = std::cout);
EOF
```
Файл examples/example1.cpp:
```
$ cat > examples/example1.cpp <<EOF
#include <print.hpp>

int main(int argc, char** argv)
{
  print("hello");
}
EOF
```
Файл examples/example2.cpp:
```
$ cat > examples/example2.cpp <<EOF
#include <print.hpp>

#include <fstream>

int main(int argc, char** argv)
{
  std::ofstream file("log.txt");
  print(std::string("hello"), file);
}
EOF
```
### 6. Второй коммит
ДОбавляем все файлы, сохраняем изменения структуры проекта и отправляем проект в удаленный репозиторий
```
$ git status
$ git add .
$ git commit -m"added sources"
$ git push origin main
```
## Создание отчета
```
$ cd ~/workspace/
$ export LAB_NUMBER=02
$ git clone https://github.com/tp-labs/lab${LAB_NUMBER}.git tasks/lab${LAB_NUMBER}
$ mkdir reports/lab${LAB_NUMBER}
$ cp tasks/lab${LAB_NUMBER}/README.md reports/lab${LAB_NUMBER}/REPORT.md
$ cd reports/lab${LAB_NUMBER}
$ edit REPORT.md
$ gist REPORT.md
```

## Homework
### Part 1
Создаем файл:
```
cat > hello_world.cpp <<EOF
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world" << endl;
    return 0;
}
EOF
```
Добавляем файл в Git и делаем коммит:
```
git add hello_world.cpp
git commit -m "Add hello_world.cpp with bad style"
```
Изменим код в файле, сделаем второй коммит и отправим на github:
```
cat > hello_world.cpp <<EOF
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello world from " << name << endl;
    return 0;
}
EOF
git commit -a -m "Add name input and personalized greeting"
git push origin main
```

### Part 2
Создадим ветку patch1, исправим код и сохраним изменения:
```
git checkout -b patch1
cat > hello_world.cpp <<EOF
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}
EOF
git commit -a -m "Remove 'using namespace std', use explicit std::"
git push -u origin patch1
```
Добавим в код комментарии, сделаем коммит, обновим ветку main и удалим ветку patch1:
```
git commit -a -m "Add comments to hello_world.cpp"
git push
git checkout main
git pull origin main
git branch -d patch1
```

### Part 3
Создадим ветку patch2, установим clang-format, сделаем коммит и пуш:
```
git checkout -b patch2
sudo apt install clang-format -y
clang-format -style=Mozilla -i hello_world.cpp
```
Далее изменим в ветке main наш файл и обнаружим конфликты.
После этого разрешим конфликты и удалим в файле ненужные маркеры:
```
git checkout patch2
git fetch origin
git rebase origin/main
nano hello_world.cpp
```
После этого:
```
git add hello_world.cpp
git rebase --continue
git push --force-with-lease origin patch2
```

## Оформление репозитория
В репозиторий были добавлены:

1)`TASK.md` - текст задания

2)`REPORT.md` - отчет

3)Файлы основной части

4)Домашняя работа

## Вывод
В ходе лабораторной работы я научился создавать репозитории, делать коммиты, создавать ветки и отправлять изменения на GitHub.



