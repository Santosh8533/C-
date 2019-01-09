/**
    Author: Santosh Tandrothu
    Date: 1/8/2019
    Problem: Given an expression, verify whether or not the brackets are balanced.
**/

/**
    Run-time: O(n) - traversing the complete string
    Space: O(n) - saving the whole string in stack (worst case: {{{{{{)
**/

#include<iostream>
#include<stack>

using namespace std;

bool areBracketsValid(const string& input){

    stack<char> s;

    for(size_t i=0;i<input.length();i++){

        char ch = input.at(i);
        if(ch == '{' || ch == '[' || ch == '('){
                s.push(ch);
        }

        else if(ch == '}'){
            if(s.empty())return false;
            else if(s.top() == '{') s.pop();
            else return false;
        }

        else if(ch == ')'){
            if(s.empty())return false;
            else if(s.top() == '(') s.pop();
            else return false;
        }

        else if(ch == ']'){
            if(s.empty())return false;
            else if(s.top() == '[') s.pop();
            else return false;
        }
    }

    if(s.empty())return true;
    else return false;
}

int main(){
    //Valid
    string input1 = "{([])}";
    cout<<"Are brackets valid?"<<areBracketsValid(input1)<<endl;

    //Invalid
    string input2 = "{{{";
    cout<<"Are brackets valid?"<<areBracketsValid(input2)<<endl;

    //Invalid
    string input3 = "]]]";
    cout<<"Are brackets valid?"<<areBracketsValid(input3)<<endl;

    //Invalid
    string input4 = "{([]}";
    cout<<"Are brackets valid?"<<areBracketsValid(input4)<<endl;

    return 0;
}
