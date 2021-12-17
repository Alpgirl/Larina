#include "class.h"
#include <iostream>
using namespace std;

int main() {
    int i;

    cout << endl << "Initial geometries: " << endl << endl;

    Square sobj(-3.0, 0.0, 1.0);
    Square sobj1(2.3, -1.4, 0.7);
    Square sobj2(-5.4, 1.2, 4.0);
    Circle cobj(2.0, 3.0, 2.0);
    Circle cobj1(7.0, -5.0, 2.5);

    sobj.coordinates(1.0);
    sobj1.coordinates(1.0);
    sobj2.coordinates(1.0);

    PlaneObject *geometry[5];
    geometry[0] = &cobj;
    geometry[1] = &sobj;
    geometry[2] = &cobj1;
    geometry[3] = &sobj1;
    geometry[4] = &sobj2;

    for (i = 0; i < 5; i++) {
        cout << i << " ";
        geometry[i] -> show();
    }

    cout << endl << "After drawing: " << endl << endl;

    geometry[1] -> rotate(65);
    geometry[1] -> move(0.6, -2.7);
    geometry[1] -> rotate(25);
    geometry[1] -> scale(0.2);
    cout << 1 << " ";
    geometry[1] -> show();

    geometry[0] -> move(-1.5, 0.2);
    geometry[0] -> scale(0.2);
    cout << 0 << " ";
    geometry[0] -> show();
    
    geometry[4] -> move(-2.3, -0.7);
    geometry[4] -> rotate(120);
    cout << 4 << " ";
    geometry[4] -> show();

    return 0;
}