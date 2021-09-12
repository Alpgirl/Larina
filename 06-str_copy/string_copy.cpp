#include <iostream>
#include <string.h>

using namespace std;
int main() {
    string str, copy = "";
    cout << "Введите строку: ";
    getline (cin, str);

    int count = 0;

    while (str[count] != '\0'){
        copy += str[count];
        count++;
    }
    cout << "Копия строки: " << copy << endl;
    return 0;
}