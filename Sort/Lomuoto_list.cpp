#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include "Lomuoto_class.h"

/*struct Node{
    Node* next = NULL;
    int val;
    Node(int _val) : val(_val), next(nullptr){}
};

struct list{
    Node* first;
    Node* last;
    list() : first(nullptr), last(nullptr){}
};*/
// nullptr - значение пустого указателя
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
        /*for (int i =0 ; i<6; i++){
            std::cout << arr[i] << " ";
        }
        std::cout<<std::endl;*/
        sort(arr, a, i);
        sort(arr, i + 1, b);
    }
    else {
        return;
    }
}

int main(){
    int j = 0;
    //int arr[7] = {3, -6, 8, 0, -1, -6, 4};
    //std::cout << sizeof(arr)/sizeof(*arr) << std:: endl;
    std::string input, N, com = "";
    std::cout << "Введите число эл-тов в массиве: ";
    std::getline(std::cin, N);
    std::cout << "Введите эл-ты массива: ";
    std::getline(std::cin, input);
    //std::cout << input << std::endl;

    std::string::difference_type n = std::count(input.begin(), input.end(), ' ');

    int *arr = new int[stoi(N)];

    if(n != stoi(N)-1) {
        std::cout << "Введено неверное число эл-тов!" << std::endl;
        return 0;
    }   

    List list;

    for (int i = 0; i < input.length(); i++){
        if(isspace(input[i])){
            list.Add(stoi(N), NULL); //stoi(com)
            com = "";
            j++;
        }
        else{
            com += input[i];
        }
    }
    list.Print();
    // sizeof(arr)/sizeof(*arr) - кол-во элементов для статического массива
    /*sort(arr, 0, j+1);
    for (int i =0 ; i<stoi(N); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;*/
    
    return 0;
}

// https://prog-cpp.ru/data-ols-oop/