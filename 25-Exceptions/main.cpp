////////////////////////////////////////////////////////////////////
//////////////// TABLE OF POSSIBLE EXCEPTIONS //////////////////////
////////////////////////////////////////////////////////////////////
// PersonalException 1  //  if amount of input elements more // 1 // 
//////////////////////////  than input number                ///////
////////////////////////////////////////////////////////////////////
// PersonalException 2  //  slice combination is a:b:c. For  // 2 //
//////////////////////////  user's convenience a and b can't ///////
//////////////////////////  be equal to 0                    ///////
////////////////////////////////////////////////////////////////////
// PersonalException 3  //  slice combination is a:b:c. a    // 3 // 
//////////////////////////  and b can't be more than n       ///////
//////////////////////////  (amount of elements in array)    ///////
////////////////////////////////////////////////////////////////////
// StandardException 1  //  incorrect input of slice         // 4 //
//////////////////////////  combination                      ///////
////////////////////////////////////////////////////////////////////
// StandardException 2  //  slice combination is a:b:c. So   // 5 //
//////////////////////////  if a > b then c < 0 or a < b     ///////
//////////////////////////  then c > 0                       ///////
////////////////////////////////////////////////////////////////////
// StandardException 3  //  slice combination is a:b:c. c    // 6 //
//////////////////////////  must not be equal to 0           ///////
////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Slice.h"
#include <cstdlib>
#include <stdlib.h> 
#include <string>

using namespace std;
int main() {
    int n, *p = new int, size, k = 0, mass[3], sum = 0, tmp, l = 0;
    char *slice_exp = new char, symbols, fig;
    string num = " ", input = "", res[100];
    cout << "Введите количество элементов в массиве: ";
    cin >> n;
    cin.ignore();

    p = new int[n];
    cout << "Введите элементы массива через пробел: ";

    while (fig != '\n') {
        cin.get(fig);
        if (fig != ' ') {
            input = input + string(1, fig);
        }
        else {
            res[l] = input;
            l += 1;
            input = "";
        }
    }
    res[l] = input;

    try {
        if (l > n - 1 || l < n - 1)
            throw 1;
    }
    catch(int except) {
        cout << "Except number: " << except << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) p[i] = stoi(res[i]);

    try {
        cout << "Введите комбинацию для слайса (важно! начало всегда с 1, например 1:5:2): ";

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

        try {
            if (mass[0] == 0 || mass[1] == 0)
                throw 2;
        }
        catch (int except) {
            cout << "Except number: " << except << endl;
            return 0;
        }

        try { 
            if (mass[0] > n || mass[1] > n)
                throw 3;
        }
        catch (int except) {
            cout << "Except number: " << except << endl;
            return 0;
        }

        try { 
            if ((mass[0] > mass[1] && mass[2] > 0) || (mass[0] < mass[1] && mass[2] < 0))
                throw 5;
        }
        catch (int except) {
            cout << "Except number: " << except << endl;
            return 0;
        }

        try {
            if (mass[2] == 0) 
                throw 6;
        }
        catch (int except) {
            cout << "Except number: " << except << endl;
            return 0;
        }

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
        cout << "Except number: " << 4 << endl;
    }

    return 0;
}