#include <iostream>
#ifdef __APPLE__
    #include <codecvt>
#endif
#include <algorithm>
#include <string>

using namespace std;

int main() {
    #ifdef __APPLE__
    wcin.imbue(std::locale(locale(""), new std::codecvt_utf8<wchar_t>));
    wcout.imbue(std::locale(locale(""), new std::codecvt_utf8<wchar_t>));
    wcerr.imbue(std::locale(locale(""), new std::codecvt_utf8<wchar_t>));
    #endif
    
    int i = 0, flag = 0;
    bool match;
    wstring word, guess_word = L"";
    wchar_t letter;
    wcout << L"Введите слово: ";
    getline(wcin, word);

    if (word.empty()) {
        return 0;
    }

    wcout << word << ' ' << word.size() << endl;
    guess_word.assign(word.size(), L'_');
    wcout << guess_word << endl;
    /*
    while(word[i] != '\0'){
        guess_word += L"_";
        wcout << guess_word << endl;
        i++;
    }*/

    while (guess_word != word) {
        match = false;
        wcout << L"Введите букву: ";
        wcin >> letter;

        for (i = 0; i < word.length(); ++i) {
            if (word[i] == letter) {
                guess_word[i] = letter;
                match = true;
            }
        }

        if (!match) {
            wcout << L"Нет такой буквы в этом слове!" << endl;
            wcout << guess_word << endl;
        } 
        else {
            wcout << L"Есть такая буква в этом слове!" << endl;
            wcout << guess_word << endl;
        }
    }  
    wcout << L"Вы угадали!" << endl;
    return 0;
}
