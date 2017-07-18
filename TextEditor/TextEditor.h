#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include<stack>

using namespace std;

class TextEditor
{
    public:
        TextEditor();
        ~TextEditor();
        void insertWord(char word[]);
        void insertCharacter(char character);
        bool deleteCharacter();
        bool backSpaceCharacter();
        void moveCursor(int position);
        void moveLeft(int position);
        void moveRight(int position);
        void findAndReplaceChar(char findWhat, char replaceWith);
        void examineTop();
        void printLeftStack();
        void printRightStack();

    protected:

    private:
        stack<char> leftStack; //Left stack
        stack<char> rightStack; //Right stack
        stack<char> testStack;  //Test stack
};

#endif // TEXTEDITOR_H
