#include <iostream>   // для ввода/вывода
#include <string>      // для работы со строками

int
main()
{
  std::string name; // переменная для имени пользователя
  std::cout << "Enter your name: "; // запрос имени
  std::cin >> name;                 // чтение имени
  std::cout << "Hello world from " << name << std::endl; // приветствие
  return 0;
}
