#include "CheckClass.h"
#include <fstream>
using namespace std;

int main() {
    double num[8], a;
    int k = 0;
    ifstream fin("coordinates.txt");
    if (!fin.is_open()) {
        cout << "Файл не может быть открыт!\n"; 
        return 1;
    }
    do
    { 
        fin >> a;
        num[k] = a;
        k++;
    }
    while (!fin.eof());

    cRect value (num[0], num[1], num[2], num[3], num[4], num[5], num[6], num[7]); 
    value.BorderInter();
    fin.close();
    return 0;
}