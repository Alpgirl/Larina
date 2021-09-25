// Minimum representable positive floating-point number
// (http://www.cplusplus.com/reference/cfloat/)
#include <iostream>
#include <cfloat>

using namespace std;
template  <class T> T machine_null(T x, T div)
{   
    T null;
    do {
        null = x;
        x /= div;
    } while(x > 0);
    return (null);  
}
int main() {
    double xd = 1.0, divd = 2.0;
    float xf = 1, divf = 2;
    long double xl = 1.0, divl = 2.0;

    cout << "Машинный ноль(FLOAT) = " << machine_null<float>(xf, divf) << endl;
    cout << "Проверка: " << FLT_MIN << endl;
    cout << "Машинный ноль(DOUBLE) = " << machine_null<double>(xd, divd) << endl;
    cout << "Проверка: " << DBL_MIN << endl;
    cout << "Машинный ноль(LONG DOUBLE) = " << machine_null<long double>(xl, divl) << endl;
    cout << "Проверка: " << LDBL_MIN << endl;
    return 0;
}

// ieee 754 to read!