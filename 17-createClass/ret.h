#include <iostream>
using namespace std;

class CRational {
    public:
        float fract;
        float set_fract(float num, float denum) {
            fract = num/denum;
            return fract;
         }

        void print(int num, int denum) {
            int x, d;
            if (num - denum * (num/denum) == 0){
                cout << num/denum << endl;
            }
            else if (num > denum) {
                x = num/denum;
                d = num - x * denum;
                cout << x << " " << d << "/" << denum << endl;
            }
            else if (num < denum) {
                cout << num << "/" << denum << endl;
            }
        }

        float sumFract(float a, float b) {
            float sum, mult;
            sum = a + b;
            mult = a * b;
            cout << sum << " " << mult << endl;
            return sum;
        }   
};
