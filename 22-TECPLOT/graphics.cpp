#include <iostream>
#include <math.h>
#define M_PI        3.14159265358979323846264338327950288   /* pi*/
#include <fstream>

using namespace std;
double step(double start, double last, int n) {
    double step;
    step = abs(start - last) / n;
    return step;
}
double sin_func(double x, double y) {
    return sin(x);
}
double sin_x_func(double x, double y){
    return sin(x) * x;
}
double z_func(double x, double y) {
    return sin(x) * sin(y);
}
double dens_stand_distrib(double x, double y) {
    double ox = 10.0, oy = 10.0, p = 0.5, mx = 0.0, my = 0.0;
    return 1.0 / (2.0 * M_PI * ox * oy * pow(1.0 - pow(p, 2), 0.5)) * \
    exp(-1.0 / (2.0 * (1 - pow(p, 2))) * (pow((x - mx)/ox, 2) - \
    2.0 * p * (x - mx) * (y - my)/(ox * oy) + pow((y - my)/oy, 2)));
}
void points_func(int n, double func(double, double), string str, double start, double step, int dimension) {
    double dx = step, x = start, y = start;
    ofstream f;
    f.open(str);
    for (int i = 0; i <= n; i++){
        if (dimension > 1) {
            for (int j = 0; j <= n; j++) {
                f << y << " " << x << " " << func(x, y) << endl;
                x = x + dx;
            }
            y = y + dx;
            x = start;
        }
        else {
        f << x << " " << func(x, y) << endl;
        x = x + dx;
        }
    }
    f.close();
}

int main() {
    
    points_func(100, sin_func, "sin_points.txt", 0.0, step(0.0, 2.0 * M_PI, 100), 1);
    points_func(200, sin_x_func, "sin_x_points.txt", -100.0, step(-100.0, 100.0, 200), 1);
    points_func(100, z_func, "z_points.txt", 0.0, step(0.0, 2.0 * M_PI, 100), 2);
    points_func(200, dens_stand_distrib, "distr_points.txt", -100.0, step(-100.0, 100.0, 400), 2);

    return 0;
}