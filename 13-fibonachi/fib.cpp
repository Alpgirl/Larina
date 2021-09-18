#include <iostream>

using namespace std;

int main() {
    int i, j, k = 0, num, a = 0, b = 1, sum;
    float num_exc;
    string data;
    cout << "Введите количество чисел Фибоначчи: ";
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
        if (num > 100) {
            cout << "Вы ввели число больше 100. Попробуйте еще раз!" << endl;
        }
        else if (num_exc && num != num_exc) {
            cout << "Вы ввели нецелое число. Попробуйте еще раз!" << endl;
        }
        else if (num < 1 or num_exc < 1) {
            cout << "Вы ввели число меньше 1. Попробуйте еще раз!" << endl;
        }
        else if (num && num == num_exc) {
            if (num == 1) {
                cout << a << endl;
            }
            else if (num == 2) {
                cout << a << " " << b << endl;
            }
            else if (num > 2) {
                cout << a << " " << b;
                for (i = 1; i < num - 1; i++) {
                    sum = a + b;
                    a = b;
                    b = sum;
                    cout << " " << sum;
                }
                cout << endl;
            }
        }
    }
    else {
        cout << "Вы ввели строку, а не число. Попробуйте еще раз!" << endl;
    }
    return 0;
}