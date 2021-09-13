#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main(){
    int i = 0, k = 0, flag = 0;
    string word, guess_word = "";
    char letter;
    cout << "Введите слово: ";
    getline(cin, word);
    while(word[i] != '\0'){
        guess_word += "_";
        i++;
    }
    while (flag == 0){
        i = 0;
        k = 0;
        cout << "Введите букву: ";
        cin >> letter;
        while(word[i] != '\0'){
            if (word[i] == letter){
                guess_word[i] = letter;
                k++;
            }
            i++;
        }
        if (k == 0){
            cout << "Нет такой буквы в этом слове!" << endl;
            cout << guess_word << endl;
        }
        else{
            cout << "Есть такая буква в этом слове!" << endl;
            cout << guess_word << endl;
        }
        if (guess_word == word){
            flag++;
            cout << "Вы угадали!" << endl;
        }
    }  
    return 0;
}
