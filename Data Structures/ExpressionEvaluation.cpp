/******************************************************************************

                             Expression Evaluator
               Given a mathematical expression. This program evaluates 
the expression and tells if it is valid or not based on the parantheses/flower braces

*******************************************************************************/

//a+(b+c)
//std::string doesn't end with a null character
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

bool ExpressionEvaluation::evaluate(string str){
    int push_count = 0;
    int pop_count = 0;
    for(int i=0;i<str.length();i++){
        if(str[i] == '{'){
            s.push(str[i]);
            push_count++;
        }
        else if(str[i] == '}'){
            char c = s.pop();
            if(c == '{'){
                pop_count++;
            }
        }
    }
    
    if(push_count == pop_count)return true;
    return false;
    

}

int main(){
    string s;
    cout << "Enter a expression";
    cin >> s ;
    ExpressionEvaluation exp;
    bool result = exp.evaluate(s);
    cout << "Expression is valid:->" << result << endl; 
    return 0;
}




