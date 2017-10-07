#include <iostream>
#include <string>
#include "dictionary.h"
using namespace std;

int main() {
    cout << "scheck version 0.1" << endl;
    cout << " type 'quit' to exit spellcheck" << endl;
    Dictionary d( "data/mydict.dat");
    string word = "dog";
    while(getline(cin, word))
    {
        if(word=="quit")
        {
            break;
        }
        if(d.Check(word))
        {
            cout << word << " is OK" << endl;
        }
        else
        {
            cout << word << " is misspelt " << endl;
        }
    }
}
