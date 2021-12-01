#include "class.h"
#include <iostream>
using namespace std;

struct transition {
    int value;
    transition *next;
    transition(int _value): value(_value) {}
};

storage :: storage(): T(NULL), tmp(NULL) {}

storage :: ~ storage () {
    if (T != NULL) 
        pop();
}

int storage :: pop() {
    int temp = T -> value;
    transition *CurEl = T;
    T = T -> next;
    delete CurEl;
    return temp;
}

void storage :: print() {
    transition *temp = T;
    while (temp != NULL) {
        cout << temp -> value << endl;
        if ((temp -> next) != NULL)
            temp = temp -> next;
        else temp = NULL;
    }
}

LIFO :: ~ LIFO () {
    if (T != NULL) 
        pop();
}

void LIFO :: push(int value) {
    transition *CurEl = new transition(value);
    CurEl -> next = T;
    T = CurEl;
}

FIFO :: ~ FIFO () {
    if (T != NULL)
        pop();
}

void FIFO :: push(int value) {
    transition *CurEl = new transition(value);
    if (T == NULL) T = CurEl;
    else tmp -> next = CurEl;
    tmp = CurEl;
}