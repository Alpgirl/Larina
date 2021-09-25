#include <iostream>
#include <cfloat>

using namespace std;

template  <class T> T machine_difference(T eps, T null)
{   
    return (null - eps);  
}
template  <class T> T machine_sum(T eps, T null)
{   
    return (null + eps);  
}
int main() {
    double epsd = 2.22045e-16, nulld = 4.94066e-324;
    float epsf = 1.19209e-07, nullf = 1.4013e-45;
    long double epsl = 1.0842e-19, nulll = 3.6452e-4951;
    cout << "Разность машинного нуля и машинного эпсилона = " << machine_difference<float>(epsf, nullf) << endl;
    cout << "Разность машинного нуля и машинного эпсилона = " << machine_difference<double>(epsd, nulld) << endl;
    cout << "Разность машинного нуля и машинного эпсилона = " << machine_difference<long double>(epsl, nulll) << endl;

    cout << "Сумма машинного нуля и машинного эпсилона = " << machine_sum<float>(epsf, nullf) << endl;
    cout << "Сумма машинного нуля и машинного эпсилона = " << machine_sum<double>(epsd, nulld) << endl;
    cout << "Сумма машинного нуля и машинного эпсилона = " << machine_sum<long double>(epsl, nulll) << endl;
    return 0;
}
