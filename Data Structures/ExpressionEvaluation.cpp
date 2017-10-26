//a+(b+c)
#include<iostream>

using namespace std;

//need a datatype to store the elements and build the stack
struct Element{
    char ele;
};

class Stack{
public:
    int top = -1;
    Element e[4];
    bool push(char);
    char pop();
    bool isEmpty();
};

class ExpressionEvaluation{
public:
    Stack s;
    bool evaluate(string);
};

/***Stack Implementation****/
bool Stack::push(char c){
    top++;
    e[top].ele = c;
    return true;
}

char Stack::pop(){
    if(top==-1)return '0';
    char ele = e[top].ele;
    top--;
    return ele;
}

bool Stack::isEmpty(){
    if(top==-1)return true;
}

/***Expression evaluation***/

bool ExpressionEvaluation::evaluate(string s){

}
