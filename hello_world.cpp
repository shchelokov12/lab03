#include <iostream>   // для std::cout, std::cin
#include <string>      // для std::string

int main() {
    std::string name;                     // переменная для имени пользователя
    std::cout << "Enter your name: ";     // запрос имени
    std::cin >> name;                     // чтение имени
    std::cout << "Hello world from " << name << std::endl;  // приветствие
    return 0;
}
