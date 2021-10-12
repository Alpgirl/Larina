#include <iostream>
using namespace std;

class CRational {
    public:
        int num;
        int denum;

        float set_fract(int num, int denum) { // ф-ция инициализации дроби числителем и знаменателем
            if (denum == 0) {
                cout << "Знаменатель = 0. Введите другое число" << endl;
                return 0;
            }
            float fract;
            fract = num/denum;
            return fract;
        }

        void check (int &num, int &denum) { // процедура сокращения дроби
            if (denum == 0) return;
            int edge = denum;
            if (num > denum) edge = num; 
            for (int i = edge/2; i >= 2; i--) {
                if ((num - i * (num / i) == 0) && (denum - i * (denum / i) == 0)) {
                    num = num / i;
                    denum = denum / i;
                }
            }
        }

        void print(int num, int denum) { // процедура вывода дроби (смешанной, правильной, целого числа)
            int x, d;
            if (denum == 0) return; 
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

        void sumFract(float a, float b) { // процедура сложения/умножения двух дробей
            float sum, mult;
            sum = a + b;
            mult = a * b;

            cout << sum << " " << mult << endl;
        }   
};

/*
class Complex{
    public:
        float re, im;
        Complex(float _re, float _im): re(-re), im(-im) {} // {} - body is not needed. Exception - ;
}
(.cpp) Complex c(1,5)
*/