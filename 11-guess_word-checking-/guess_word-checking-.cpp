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
    
    int i = 0, flag = 0, match;
    wstring word, guess_word = L"", letter;
    bool repeat, loose;
    wcout << L"Введите слово: ";
    getline(wcin, word);

    if (word.empty()) {
        return 0;
    }

    guess_word.assign(word.size(), L'_');
    wcout << guess_word << endl;

    while (guess_word != word) {
        match = 0;
        repeat = false;
        loose = false;
        wcout << L"Введите букву: ";
        wcin >> letter;
        
        if (letter.size() == 1) {
            for (i = 0; i < word.length(); ++i) {
                if (guess_word[i] == letter[0]){ // условие на проверку, появлялась ли буква в слове
                    repeat = true;
                }
                if (word[i] == letter[0] && guess_word[i] == '_') { // условие на проверку, есть ли буква в введенном слове 
                    guess_word[i] = letter[0];
                    match++;
                }
            }
            if (match == 0) {
                if (repeat){
                    wcout << L"Эта буква уже была, попробуйте еще раз!" << endl;
                    wcout << guess_word << endl;
                }
                else {
                    wcout << L"Нет такой буквы в этом слове!" << endl;
                    wcout << guess_word << endl;
                }
            } 
            else {
                wcout << L"Есть такая буква в этом слове!" << endl;
                wcout << guess_word << endl;
            }
        }
        else {
            if (letter == word) {
                guess_word = letter;
            }
            else {
                loose = true;
                break;
            }
        }
       
    }  
    if (loose) {
        wcout << L"К сожалению, вы не угадали слово. Вы проиграли." << endl;
    }
    else {
        wcout << L"Вы угадали!" << endl;
    }
    return 0;
}
