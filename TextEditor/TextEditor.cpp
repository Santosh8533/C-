#include "TextEditor.h"
#include<iostream>
//#include<stack>

using std::cout;
using std::cin;

TextEditor::TextEditor()
{
    //ctor
    cout<<"Yes"<<endl;
}

TextEditor::~TextEditor()
{
    //dtor
}

/***************Examine top of Stack******************/
void TextEditor::insertWord(char word[]){

    int i=0; //Program crashed when failed to initialize the i
    while(word[i]!='\0'){
        //cout<<word[i]<<"\t";
        leftStack.push(word[i]);
        i++;
    }

};
/******************************************************/

/***************Insert Character******************/
void TextEditor::insertCharacter(char character){
    leftStack.push(character);
};
/******************************************************/

/***************Delete a Character******************/
bool TextEditor::deleteCharacter(){
    if(rightStack.empty()){
        cout<<"There are no elements to delete. Place the cursor at right position"<<endl;
        return false;
    }
    else{
        rightStack.pop();
        return true;
    }
};
/******************************************************/

/***************Backspace on a Character******************/
bool TextEditor::backSpaceCharacter(){
    if(leftStack.empty()){
        cout<<"There are no elements to perform backspace. Insert elements"<<endl;
        return false;
    }
    else{
        leftStack.pop();
        return true;
    }
};
/******************************************************/

/*********************Move Cursor*********************/
void TextEditor::moveCursor(int position){
    int leftStackSize,newPosition;
    leftStackSize=leftStack.size();
    if(position<leftStackSize)
        moveLeft(position);
    else{
        newPosition=position-leftStackSize;
        moveRight(newPosition);
    }
};
/******************************************************/

/***************Move cursor to the left******************/
void TextEditor::moveLeft(int position){
    int leftStackSize=leftStack.size();
    while(position!=leftStackSize){
        rightStack.push(leftStack.top());
        leftStack.pop();
    }
};
/******************************************************/

/***************Move cursor to the right******************/
void TextEditor::moveRight(int position){

    int rightStackSize=rightStack.size(); //making signed(r.h.s) to unsigned
    if((position==rightStackSize) || (position)>rightStack.size()){
        cout<<"Cannot move the cursor further towards right"<<endl;
    }
    while(position!=rightStackSize){
        leftStack.push(rightStack.top());
        rightStack.pop();
    }
};
/******************************************************/

/***************Find and Replace ******************/
void TextEditor::findAndReplaceChar(char findWhat, char replaceWith){
    int newPosition=1, originalCursorPosition = leftStack.size();

    moveCursor(0); //move all the elements from left stack to right stack
    //move elements from right stack to left stack after examining
    while(!rightStack.empty()){
        if(rightStack.top()==findWhat){
            deleteCharacter();
            insertCharacter(replaceWith);
        }
        else
            moveCursor(newPosition); //If the element doesnt match, it moves from right stack to left stack
        newPosition++;
    }
    moveCursor(originalCursorPosition);
};
/******************************************************/

/***************Examine top of Stack******************/
void TextEditor::examineTop(){

    if(leftStack.empty())
        cout<<"leftStack: empty \t";
    else
        cout<<"leftStack: "<<leftStack.top()<<","<<leftStack.size()<<"\t\t";
    if(rightStack.empty())
        cout<<"rightStack: empty \t";
    else
        cout<<"rightStack: "<<rightStack.top()<<","<<rightStack.size()<<"\t\t";
};
/******************************************************/
