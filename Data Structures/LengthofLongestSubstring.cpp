/**

What are the lessons learned from this program?
1. Divide the problem into sub-problems
2. Solve one by one
3. Put them together
4. Solve brute-force first that will give an understanding of the problem, redundancy in the code.
    So, that you could come up the best approach to optimize the problem
**/


/**
    1. Algorithmic Time-Complexity:  
    2. Space Complexity:
**/
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
            //cout << test.at(_start) << "\t";
        }

        else if(stak.empty()){return false;}
        else if(test.at(_start) == '}' || test.at(_start) == ')' || test.at(_start) ==']' ){

            switch(test.at(_start)){
                case '}':
                    if(stak.top() == '{'){
                        //cout << test.at(_start) << "\t";
                        stak.pop();
                    }
                    else{
                        //cout << "Expression is not balanced" <<endl;
                        return false;
                    }
                    break;

                case ')':
                    if(stak.top() == '('){
                        //cout << test.at(_start) << "\t";
                        stak.pop();
                    }
                    else{
                        //cout << "Expression is not balanced" <<endl;
                        return false;
                    }
                    break;

                case ']':
                    if(stak.top() == '['){
                        //cout << test.at(_start) << "\t";
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
    /** Stack is not empty:This indicates only open ({ brakcets
    are present in the stack
    **/

    if(stak.empty())return true;
    else return false;
}

int main(){
    //string test = "[()]{}{[()()]()}";
    string test = "{()";
    //string test = "abcde";
    int _start = 0;
    int _end = test.length()-1;
    int noOfSubstrings = 0, MaxLength = 0;
    for(int i=_start;i<=_end;i++){
        for(int j=1;j<=(_end-i+1);j++){
            //cout << test.substr(i,j) << "\n";
            string temp = test.substr(i,j);
            //cout << "Are brackets balanced?" << balancedBrackets(test.substr(i,j)) << endl;
            bool balanced = balancedBrackets(temp);
            if(balanced == true && (temp.length() > MaxLength)){
                    cout << temp << "\n";
                    MaxLength = temp.length();
                    cout << MaxLength << endl;
            }
            noOfSubstrings++;
            temp = "";
        }

        cout << "\n";
    }
    cout << "No of Substrings->" << noOfSubstrings << endl;
    cout << "Length of longest substring->>" << MaxLength << endl;
    /** n(n+1)/2 **/
   // cout << "Are brackets balanced?" << balancedBrackets(test) << endl;
    return 0;
}
