#include "ret.h"
using namespace std;

int main() {
    CRational fract;
    int a = 46, b = 22;
    int *p1, *p2;
    p1 = &a;
    p2 = &b;

    fract.set_fract(a, b);
    fract.check(*p1, *p2);
    fract.print(a, b);

    return 0;
}