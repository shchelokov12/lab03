#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;  // переменная для имени пользователя
    cout << "Enter your name: ";  // запрос имени
    cin >> name;  // чтение имени
    cout << "Hello world from " << name << endl;  // приветствие
    return 0;
}
