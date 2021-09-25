// Difference between 1 and the least value greater than 1 that is representable
// (http://www.cplusplus.com/reference/cfloat/)
#include <iostream>
#include <cfloat>

using namespace std;
//template <typename T> std::string type_name();
template  <class T> T machine_epsilon(T one)
{   
    T eps = 1.0;
    T div = 0.5;
    while (one + eps * div > one)
    {   
        eps *= div;
    } 
    return (eps);  
    //cout << "Машинный эпсилон " << typeid(eps).name() << " = " << eps << endl;
    //cout << numeric_limits<T>::epsilon() << endl;
}
int main() {
    cout << "Машинный эпсилон (FLOAT) = " << machine_epsilon<float>(1.0) << endl;
    cout << "Проверка: " << FLT_EPSILON << endl;
    cout << "Машинный эпсилон (DOUBLE) = " << machine_epsilon<double>(1.0) << endl;
    cout << "Проверка: " << DBL_EPSILON << endl;
    cout << "Машинный эпсилон (LONG DOUBLE) = " << machine_epsilon<long double>(1.0) << endl;
    cout << "Проверка: " << LDBL_EPSILON << endl;
    
    return 0;
}