#include <iostream>
#include <fstream>
#include <chrono>


void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int LeftChild (int i) {
    return (2 * i + 1);
}


int RightChild (int i) {
    return (2 * i + 2);
}


void ShiftDown(int* A, int i, int size) {
    int left = LeftChild(i);
    int right = RightChild(i);
    int largest = i;
    if (left < size && A[left] > A[largest]) {
        largest = left;
    }
    if (right < size && A[right] > A[largest]) {
        largest = right;
    }
    if (largest != i) {
        Swap(&A[i], &A[largest]);
        ShiftDown(A, largest, size);
    }
    return;
}


void Build(int* A, int size) {
    for (int i = (size-1)/2; i>=0; i--) {
        ShiftDown(A, i, size);
    }
}


void Sort (int* A, int size) {
    Build(A, size);
    for (int i = size-1; i >= 1; i--) {
        Swap(&A[0], &A[i]);
        size--;
        ShiftDown(A, 0, size);
    }
    return;
}


int main()
{
    int cnt = 0, j;
    std::string input, N, com = "";

    // Чтение данных из файла, создание числового массива
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    if(!in or !out){
        std::cout << "Can't open the file" << std::endl;
        return -1;
    }
    while(!in.eof()){
        getline(in, input);
        if (cnt == 0) N = input;
        cnt++;
     }

    int *arr = new int[stoi(N)];

    std::string::difference_type n = std::count(input.begin(), input.end(), ' ');
    if(n != stoi(N)-1) {
        std::cout << "Введено неверное число эл-тов!" << std::endl;
        return 0;
    }

    for (int i = 0; i <= input.length(); i++){
        if(isspace(input[i])){
            arr[j] = stoi(com);
            com = "";
            j++;
        }
        else{
            com += input[i];
        }
    }
    arr[j] = stoi(com);

    // Начало отсчета времени
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    Sort(arr, stoi(N));

    // Вывод в файл отсортированного массива
    for (int i =0 ; i < stoi(N); i++){
        out << arr[i] << " ";
    }
    out << std::endl;

    //Конец отсчета времени
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[mcs]" << std::endl;

    in.close();
    out.close();
    return 0;
}
