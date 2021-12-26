#ifndef SLICE_H
#define SLICE_H
#include "Slice.h"
#include <iostream>
using namespace std;

int* Cslice :: Parser(int start, int stop, int step) {
    int k, b = 0;

    if (abs(step) == 1) size = abs((abs(stop - start) + 1) / abs(step));
    else if (step - 2*(step/2) == 0) size = abs((abs(stop - start) + 1) / (abs(step)));
    else  if (step - 2*(step/2) != 0) size = abs((abs(stop - start) + 1) / (abs(step))) + 1;
            
    if (start < 0) start = n + 1 + start;
    if (stop < 0) stop = n + stop;

    tmp_2 = new int[size];

    if (step > 0) {
        for (k = start - 1; k < stop; k = k + step) {
            *(tmp_2 + b) = *(tmp + k);
            b++;
        }
    }
    if (step < 0) {
        for (k = start - 1; k >= stop - 1; k = k + step) {
            *(tmp_2 + b) = *(tmp + k);
            b++;
        }
    }
    return tmp_2;
}

void Cslice :: print() {
    cout << "Результат слайса: " ; 
    for (int i = 0; i < size; i++) cout << *(tmp_2 + i) << " ";
    cout << endl;
}
#endif 