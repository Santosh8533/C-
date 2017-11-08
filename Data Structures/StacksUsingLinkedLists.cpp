#include<iostream>

using namespace std;

class Element{
    int ele;
    Element *next;
};

class Stack{
public:
    int top,StackSize;
    Stack *s[10];
    Stack():top(-1), StackSize(10){}
    bool isStackEmpty();
    bool isStackFull();
    bool push(int);
    Stack pop();
    Stack peek();

};

//Check if Stack is empty
bool Stack::isStackEmpty(){
    if(top == -1){cout << "Stack is empty" << endl;return true;}
    return false;
}

//Check if stack is full
bool Stack::isStackFull(){
    if(top == 9){cout << "Stack is empty" << endl; return true;}
    return false;
}

//push an element
bool Stack::push(int ele){
    if(isStackFull()){cout << "Stack is full" << endl;}
    e = new Element;
    e.ele = ele;
    e.next = NULL;
    if(top == -1){s[++top] = ele;}
    else{
        temp = s[top];
        while(s[top]->next!= NULL){

        }
    }

}
int main(){
    Stack s;
    return 0;
}
