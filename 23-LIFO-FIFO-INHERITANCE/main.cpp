#include <iostream>
#include "class.h"
//#include "functions.cpp"
 
using namespace std;
int main() {
    LIFO f1;
    FIFO f2;
    cout << "STEK session:" << endl;

    f1.push(100);
    f1.push(200);
    f1.push(400);
    f1.pop();
    f1.push(500);
    f1.push(600);
    f1.print();

    cout << "QUEUE session:" << endl;

    f2.push(100);
    f2.push(200);
    f2.push(300);
    f2.push(500);

    f2.push(700);
    f2.pop();
    f2.pop();
    f2.print();

    return 0;
}