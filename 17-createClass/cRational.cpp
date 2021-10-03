#include "ret.h"
using namespace std;

int main() {
    CRational fract;

    cout << fract.set_fract(5, 3) << endl;
    fract.print(5, 3);
    return 0;
}