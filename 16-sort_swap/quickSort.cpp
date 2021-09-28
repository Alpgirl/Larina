#include <iostream>
#include <cstdlib> /* srand, rand */
#include <ctime>  /* time */
#include <stdio.h> /* NULL */

using namespace std;

void printArr(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void exchange1(int &a, int &b) { // in sum
    if (a != b) {
        a = a + b;
        b = a - b;
        a = a - b;
    }
}
void exchange2(int &a, int &b) { // in temporary valiable
    int tmp;
    tmp = b;
    b = a;
    a = tmp;
}
void exchange3(int &a, int &b) { // in bit operations
    if (a != b) {
        a = a ^ b; // a = 101^110 = 011
	    b = a ^ b; // b = 011^110 = 101
	    a = a ^ b; // a = 011^101 = 110
    }
}
void quickSort (int *arr, int f, int l) {
    int i = f, j = l;
    int m = arr[(i + j)/2], tmp;

    while (i <= j) {
        while (arr[i] < m)
            i++;
        while (arr[j] > m)
            j--;
        if (i <= j)
        {
            exchange3(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (j > f)
        quickSort(arr, f, j);
    if (i < l)
        quickSort(arr, i, l);
}
int main() {
    int arr[100];
    int size, f, l;

    cout << "Введите число элементов в массиве: ";
    cin >> size;

    srand (time(NULL));
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 200 - 100; // in the range 0 to 99
    }
    
    f = 0; l = size - 1;
    cout << "Исходный массив: ";
    printArr(arr, size);
    quickSort(arr, f, l);
    cout << "Отсортированный массив: ";
    printArr(arr, size);
    return 0;
}