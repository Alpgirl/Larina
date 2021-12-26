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
        Cslice(int *p, int n) : tmp(p), n(n) {}
        Cslice() : tmp_2(NULL) {}

        int* Parser(int, int, int);
        void print();
};

