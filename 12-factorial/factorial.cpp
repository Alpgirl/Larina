#include <string>
#include <cstdlib>
#include <stdlib.h> 
#include <iostream>

using namespace std;
int main() {
    int i, j, k = 0, num, fact = 1;
    float num_exc;
    string data;
    cout << "Введите число: ";
    cin >> data;

   // if (data.empty()) {
   //     return 0;
   // }

    for (i = 0; i < data.length(); i++) {
        if (isdigit(data[i]) or data[i] == '-' or data[i] == '.' or data[i] == ',') {
            k++;
        }
    } 

    if (k == data.length()) {
        num_exc = stof(data);
        num = stoi(data);
        if (num == 0 && num_exc == 0) {
            cout << num << "! = " << 1 << endl;
        }
        else if (num > 100000) {
            cout << "Вы ввели число больше 100000. Попробуйте еще раз!" << endl;
        }
        else if (num < 0 or num_exc < 0) {
            cout << "Вы ввели отрицательное число. Попробуйте еще раз!" << endl;
        }
        else if (num_exc && num != num_exc) {
            cout << "Вы ввели нецелое число. Попробуйте еще раз!" << endl;
        }
        else if (num && num == num_exc) {
            for (i = 1; i < num; i++) {
                fact = fact * (i + 1);
            }
            cout << num << "! = " << fact << endl;
        }
    }
    else {
        cout << "Вы ввели строку, а не число. Попробуйте еще раз!" << endl;
    }
    return 0;
}