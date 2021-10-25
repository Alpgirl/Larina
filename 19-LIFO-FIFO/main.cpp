#include<iostream>
#include "FIFO_LIFO.h"

using namespace std;

int main() {
    FIFO f1;
    LIFO f2;

    f1.push(100);
    f1.push(200);
    f1.push(500);

    f2.push(100);
    f2.push(300);
    f2.push(400);
 
    cout << "FIFO:" << endl;
    f1.print();
    cout << endl;
    cout << "LIFO:" << endl;
    f2.print();
    //f2.pop();

    /*f2.print();*/
    return 0;
}