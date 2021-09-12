#include <iostream>
using namespace std;

int main() {
    int min = 0, max = 100, num, k = 0, comparedNum;
    while (num != 3){
        comparedNum = (min + max)/2;
        cout << "N больше " << comparedNum << "(1 да, 2 нет, 3 равно)?" << endl;
        cin >> num;
        k++;
        if (num == 1){
            min = comparedNum;
        }
        if (num == 2){
            max = comparedNum;
        }
        if (num == 3){
            cout << "Вы задумали " << comparedNum << "!А я молодец! Количество попыток: " << k << endl;
            break;
        }
    }
    return 0;
}