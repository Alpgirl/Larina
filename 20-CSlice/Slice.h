#include <iostream>
using namespace std;
class Cslice {
    private:
        int *tmp, n;
        int *tmp_2 = new int;
        int size;
    public:
        ~Cslice() {
		    delete tmp_2;
	    }

        Cslice() : tmp_2(NULL) {}
        Cslice(int *p, int n) : tmp(p), n(n) {}
        int* Parser(int start, int stop, int step) {
            int k, b = 0;

            if (abs(step) == 1) size = abs((abs(stop - start) + 1) / abs(step));
            else size = abs((abs(stop - start) + 1) / (abs(step))) + 1;
            
            if (start < 0) start = n + 1 + start;
            if (stop < 0) stop = n + stop;

            tmp_2 = new int[size];

            if (step > 0) {
                for (k = start - 1; k < stop; k = k + step) {
                    *(tmp_2 + b) = *(tmp + k);
                    b++;
                }
            }
            if (step < 0) {
                for (k = start - 1; k >= stop - 1; k = k + step) {
                    *(tmp_2 + b) = *(tmp + k);
                    b++;
                }
            }
           return tmp_2;
        }
        void print() {
            cout << "Результат слайса: " ; 
            for (int i = 0; i < size; i++) cout << *(tmp_2 + i) << " ";
            cout << endl;
        }
};

