#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <fstream>

void swap(int *arr, int ind1, int ind2){
    int tmp;
    tmp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = tmp;
}


void sort(int *arr, int a, int b){
    if(a < b){
        int pivot = arr[a], i = a;
        for (int j = a + 1; j < b; j++){
            if (arr[j] <= pivot){
                i += 1;
                swap(arr, i, j);
            }
        }
        swap(arr, a, i);
        sort(arr, a, i);
        sort(arr, i + 1, b);
    }
    else {
        return;
    }
}


int main(){
    int j = 0, cnt = 0;
    std::string input, N, com = "";

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

    sort(arr, 0, j+1);

    for (int i =0 ; i < stoi(N); i++){
        out << arr[i] << " ";
    }
    out << std::endl;

    //Конец отсчета времени
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[mcs]" << std::endl;
    in.close();
    out.close();
    return 0;
}

/////////////////////////////////
////////// SOME NOTES ///////////
/////////////////////////////////
// 1 // sizeof(arr)/sizeof(*arr) - кол-во элементов для статического массива
// 2 // rand() % (N) + 1 - рандомное число от 0 до N включительно