#include <iostream>
#include <fstream>

void ElementsInBag(int **cell, int *mi, int i, int j, std::ofstream &out){
    if (i > 0){
        if(cell[i][j] != cell[i-1][j]){
            out << i+1 << std::endl;
            ElementsInBag(cell, mi, i-1, j-mi[i]+1, out);
        }
        else{
            ElementsInBag(cell, mi, i-1, j-1, out);
        }
    }
    else {
        if (cell[i][j] != 0) out << i+1 << std::endl;
        return;
    }
}

int main() {
    int N, M, j = 0; // N < 100, M < 10000
    int cnt = 0, tmp, start_weight;

    std::string input, com, arrays = "", elements_in = "";

    // Чтение данных из файла
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    if(!in or !out){
        std::cout << "Can't open the file" << std::endl;
        return -1;
    }

    // Получаем M и N - вместимость рюкзака и кол-во предметов, в строку arrays записываем значения весов и ценностей
    while(!in.eof()){
        getline(in, input);
        com = "";
        if (cnt == 0) {
            for (int i = 0; i < input.length(); i++){
                if(isspace(input[i])){
                    N = stoi(com);
                    com = "";
                }
                else com += input[i];
            }
            M = stoi(com);
        }
        else if (cnt > 0){
            arrays += input+' ';
        }
        cnt++;
    }

    // Создаем массивы весов и ценностей
    int *mi = new int[N];
    int *ci = new int[N];

    for (int i = 0; i < arrays.length(); i++){
        if(isspace(arrays[i])) {
            if (j < N) mi[j] = stoi(com);
            else ci[j-N] = stoi(com);
            com = "";
            j++;
        }
        else {
            com += arrays[i];
        }
    }

    // Создаем таблицу результатов cell
    int **cell = new int*[N];

    for (int h = 0; h < N; h++){
        cell[h] = new int[M];
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cell[i][j] = 0;
        }
    }

    // Реализация алгоритма динамического программирования для оптимизации загрузки рюкзака
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (i == 0){
                if (mi[i] <= j+1) cell[i][j] = ci[i];
            }
            else{
                if (mi[i] < j+1){
                    tmp = ci[i] + cell[i-1][j-mi[i]];
                    if (tmp < cell[i-1][j]) cell[i][j] = cell[i-1][j];
                    else cell[i][j] = tmp;
                }
                else if (mi[i] > j+1) cell[i][j] = cell[i-1][j];
                else{
                    if (ci[i] < cell[i-1][j]) cell[i][j] = cell[i-1][j];
                    else cell[i][j] = ci[i];
                }
            }
        }
    }

    /*for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            std::cout<< cell[i][j] << " ";
        }
        std::cout << std::endl;
    }*/

    // Определение элементов, помещаемых в рюкзак, вывод их в файл
    ElementsInBag(cell, mi, N-1, M-1, out);

    free(ci);
    free(mi);
    in.close();
    out.close();
    return 0;
}