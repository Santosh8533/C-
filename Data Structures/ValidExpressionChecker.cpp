    /**
        Author: Santosh Tandrothu
        Date: 06/17/2018
        Problem: Given an mathematical expression, check if has balanced parantheses
        Example: (1+2)*3, }{1+2*(3+4)}
        Answer:  (1+2)*3= Valid, }{1+2*(3+4)} = Not Valid
    **/

    /***
        Time Complexity = O(n)
        Space Complexity = O(stack size)
    **/
#include <bits/stdc++.h>

using namespace std;

bool hasMatchingParantheses(string strExpression) {
    stack<char> s;
    char c;
    int len = strExpression.length();
    for(int i=0;i<len;i++){
        //To catch closing braces in the beginning Ex: }(1+2)*3
        if((strExpression[i]==')' || strExpression[i]=='}' || strExpression[i]==']') && s.empty()){return false;}

        else if(strExpression[i]=='(' || strExpression[i]=='{' || strExpression[i]=='['){
            s.push(strExpression[i]);
        }

        else if((strExpression[i]==')' || strExpression[i]=='}' || strExpression[i]==']') && !s.empty()){
            switch(strExpression[i]){
                case ')':
                    c = s.top();
                    s.pop();
                    if(c != '('){return false;}
                    break;

                case '}':
                    c = s.top();
                    s.pop();
                    if(c != '{'){return false;}
                    break;

                case ']':
                    c = s.top();
                    s.pop();
                    if(c != '['){return false;}
                    break;
            }
        }
    }
    //this condition covers the case: (1+2+(3) || (1+2+(
    if(s.empty()) return true;
    return false;

}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    bool res;
    string strExpression;
    getline(cin, strExpression);

    res = hasMatchingParantheses(strExpression);
    fout << res << endl;

    fout.close();
    return 0;
}
