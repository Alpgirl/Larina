// Maximum finite representable floating-point number
// (http://www.cplusplus.com/reference/cfloat/)
#include <iostream>
#include <cfloat>

using namespace std;

template  <class T> T machine_infinity(T x, T eps)
{   
    T inf;
    while (x < x * (2.0 - eps)) {
        inf = x;
        x *= (2.0 - eps);
    }
    return (inf);  
}
int main() {
    double xd = 1.0, epsd = 2.22045e-16;
    float xf = 1, epsf = 1.19209e-07;
    long double xl = 1.0, epsl = 1.0842e-19;

    cout << "Машинная бесконечность(FLOAT) = +-" << machine_infinity<float>(xf, epsf) << endl;
    cout << "Проверка: +-" << FLT_MAX << endl;
    cout << "Машинная бесконечность(DOUBLE) = +-" << machine_infinity<double>(xd, epsd) << endl;
    cout << "Проверка: +-" << DBL_MAX << endl;
    cout << "Машинная бесконечность(LONG DOUBLE) = +-" << machine_infinity<long double>(xl, epsl) << endl;
    cout << "Проверка: +-" << LDBL_MAX << endl;

    return 0;
}