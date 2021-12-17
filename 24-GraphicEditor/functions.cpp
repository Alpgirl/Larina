#ifndef CLASS_H
#define CLASS_H

#include "class.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 4.0 * atan(1.0)
using namespace std;

void Circle :: move(float x, float y) {
    centerX += x;
    centerY += y;
}
void Circle :: scale(float coeff) {
    radius *= coeff;
}
void Circle :: rotate(int) {}

void Circle :: show() {
    cout << "Circle, center (" << setprecision(2) << centerX << "," << centerY << "), R = " << radius << endl;;
}
void Square :: coordinates(float coeff) {
    radius *= coeff * 0.5;
    mass[0][0] = centerX - radius; mass[0][1] = centerY - radius;
    mass[1][0] = centerX - radius; mass[1][1] = centerY + radius;
    mass[2][0] = centerX + radius; mass[2][1] = centerY + radius;
    mass[3][0] = centerX + radius; mass[3][1] = centerY - radius;
}
void Square :: move(float x, float y) {
    for (int i = 0; i < 4; i++) {
        mass[i][0] += x; 
        mass[i][1] += y;
    }
    centerX += x;
    centerY += y;
}
void Square :: rotate(int angle) {
    float vectorX, vectorY, radian;

    radian = -angle * PI / 180.0;
            
    for (int i = 0; i < 4; i++) {
        vectorX = mass[i][0] - centerX; vectorY = mass[i][1] - centerY;
        mass[i][0] = centerX + vectorX * cos(radian) - vectorY * sin(radian);
        mass[i][1] = centerY + vectorX * sin(radian) + vectorY * cos(radian);
    }
}
void Square :: scale(float coeff) {
    float vectorX, vectorY;
    for (int i = 0; i < 4; i++) {
        vectorX = mass[i][0] - centerX; vectorY = mass[i][1] - centerY;
        vectorX *= coeff; vectorY *= coeff;
        mass[i][0] = vectorX + centerX; mass[i][1] = vectorY + centerY;
    }
}
void Square :: show() {
    cout << "Square, tops: " << setprecision(2);
    for (int i = 0; i < 4; i++)
        cout << "(" << mass[i][0] << "," << mass[i][1] << ") ";
    cout << endl;
}
#endif 