#include <iostream>
#include "TextEditor.h"
//#include<string>
using namespace std;

int main()
{
    char findWhat ='a', replaceWith='A';
    cout << "Text Editor begins running" << endl;
    char word[10];
    TextEditor txt;
    cout<<"Enter the word to be inserted:"<<endl;
    cin.getline(word,10);
    txt.insertWord(word);
    cout<<"Inserting the word:\t\t";
    txt.examineTop();

    cout<<"\nEnter the word to be inserted:"<<endl;
    cin.getline(word,10);
    txt.insertWord(word);
    cout<<"Inserting the word:\t\t";
    txt.examineTop();

    cout<<"Move cursor to the position 5:";
    txt.moveCursor(5);
    txt.examineTop();

    cout<<"Move cursor to the position 7:";
    txt.moveCursor(7);
    txt.examineTop();

    for(int i=0;i<3;i++){
        if(!txt.deleteCharacter())
            cout<<"There is nothing to delete. Move your cursor accordingly to delete the character";
        else
            cout<<"Delete characters using DEL:";
        txt.examineTop();
    }
    //txt.printLeftStack();
    //find and replace
    //txt.findAndReplaceChar(findWhat,replaceWith);
    //txt.printLeftStack();
    //txt.printRightStack();
    return 0;
}
