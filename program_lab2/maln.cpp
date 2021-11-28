#include <iostream>
#include "math.h"
#include <curses.h>

using namespace std;
 
// структура, которую возвращает функция поиска букв
struct vowels_and_consonants
{
    int vowels;
    int consonants;
    int difference;
    string more_letters;
};
 
// есть ли символ в строке?
bool my_find(char a, string str)
{
    for (uint32_t i = 0; i < str.length(); i++)
    {
        if (str[i] == a)
        {
            return true;
        }
    }
    return false;
}
//
//// функция подсчета букв
//vowels_and_consonants counting_letters(char *arr, int len)
//{
//    string vowels_letters = "aeiouy";
//    string consonants_letters = "bcdfghjklmnpqrstvwxz";
//    int consonants = 0;
//    char letters_consonants[consonants_letters.size()];
//    int difference;
//    string more_letters;
//    vowels_and_consonants v_n_c;
//    return v_n_c;
//}
 
int main()
{
    int size;
    cout << "Enter array limit: ";
    cin >> size;
 
    char arr[size];
 
    char eoi = '*';
 
    string x;
    
    while (true) {
        if (!my_find(getch(), "aeiouy")) {
            char a = getch();
        }
        //cout << a << endl;
    }
}
