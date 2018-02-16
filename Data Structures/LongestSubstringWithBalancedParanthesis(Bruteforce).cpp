#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool balancedBrackets(string test){

    stack<char> stak;
    int _start = 0;
    int _end = test.length()-1;

    while(_start<=_end){
        if(test.at(_start) == '{' || test.at(_start) == '(' || test.at(_start) =='[' ){
            stak.push(test.at(_start));
        }

        else if(stak.empty()){return false;}
        else if(test.at(_start) == '}' || test.at(_start) == ')' || test.at(_start) ==']' ){

            switch(test.at(_start)){
                case '}':
                    if(stak.top() == '{'){
                        stak.pop();
                    }
                    else{
                        return false;
                    }
                    break;

                case ')':
                    if(stak.top() == '('){
                        stak.pop();
                    }
                    else{
                        return false;
                    }
                    break;

                case ']':
                    if(stak.top() == '['){
                        stak.pop();
                    }
                    else{
                        //cout << "Expression is not balanced" <<endl;
                        return false;
                    }
                    break;
            }

        }
        _start++;
    }

    if(stak.empty())return true;
    else return false;
}

int main(){
    string test = "[()]{}{[()()]()}";
    //string test = "{()";
    //string test = "abcde";
    int _start = 0;
    int _end = test.length()-1;
    int noOfSubstrings = 0, MaxLength = 0;
    for(int i=_start;i<=_end;i++){
        for(int j=1;j<=(_end-i+1);j++){
            string temp = test.substr(i,j);
            bool balanced = balancedBrackets(temp);
            if(balanced == true && (temp.length() > MaxLength)){
                    MaxLength = temp.length();
            }
            noOfSubstrings++;
            temp = "";
        }
    }
    cout << "No of Substrings->" << noOfSubstrings << endl;
    cout << "Length of longest substring->>" << MaxLength << endl;
    /** n(n+1)/2 **/
    return 0;
}
