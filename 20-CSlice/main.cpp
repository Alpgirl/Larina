#include <iostream>
#include "Slice.h"
#include <string>

using namespace std;
int main() {
    int n, *p = new int, size, k = 0, mass[3], sum = 0, tmp;
    char *slice_exp = new char, symbols;
    string num = " ";
    cout << "Введите количество элементов в массиве: ";
    cin >> n;

    p = new int[n];
    cout << "Введите элементы массива через пробел: ";
    for (int i = 0; i < n; i++) cin >> p[i];

    cout << "Введите комбинацию для слайса (важно! начало всегда с 1, например 1:5:2): ";

    try {
        cin >> slice_exp;
        size = strlen(slice_exp);
        for (int i = 0; i < size; i++) {
            if (slice_exp[i] != ':') {
                num = num + slice_exp[i];
            }
            else {
                if (num == " " && k == 0) mass[k] = 1;
                else if (num == " " && k == 1) mass[k] = n;
                else if (num != " ") mass[k] = stoi(num);
                k++;
                num = " ";
            } 
        }
        mass[k] = stoi(num);
        if (mass[2] < 0 && mass[0] == 1 && mass[1] == n) {
            tmp = mass[0];
            mass[0] = mass[1];
            mass[1] = tmp;
        }
        else if (mass[2] < 0 && mass[0] == 1) mass[0] = n;
        else if (mass[2] < 0 && mass[1] == n) mass[1] = 1;

        Cslice value (p, n);
        value.Parser(mass[0], mass[1], mass[2]);
        value.print();
    }
    catch(...) {
        cout << "Некорректная комбинация для слайса. Попробуйте еще раз!" << endl;
    }

    return 0;
}