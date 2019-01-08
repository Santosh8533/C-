/**
    Author: Santosh Tandrothu
    Date: 1/7/2019
    Problem: Find the position of last closed valid paranthesis in a string given the position of first open paranthesis
**/

/**
    Run-time complexity: O(n) - traverse through entire string if ( is at 0th position - worst case
    Space complexity: O(1)
**/

#include<iostream>

using namespace std;

size_t findLstClsdParanPos(const string& str, size_t startParanPos){
    size_t balParanCount = 0;

    for(size_t position = startParanPos+1;position < str.length(); position++){
        char c = str.at(position);

        if(c=='('){
                balParanCount++;
           }
           else if(c == ')'){
                if(balParanCount == 0){
                    return position;
                }
                else{
                    --balParanCount;
                }
           }
    }

    throw invalid_argument ("No closing paranthesis :(");
}

int main(){
    string str("I(love(eggs))");
    int startParanPos = 1;
    cout<<"The position of last closed valid  paranthesis in the sentence:"<<findLstClsdParanPos(str,startParanPos)<<endl;
    string str1("I(love((eggs))");
    cout<<"The position of last closed valid  paranthesis in the sentence:"<<findLstClsdParanPos(str1,startParanPos)<<endl;
    return 0;
}
