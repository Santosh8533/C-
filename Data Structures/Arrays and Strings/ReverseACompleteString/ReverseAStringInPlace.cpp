/**
    Author: Santosh Tandrothu
    Date: 12/18/2018
    Problem: Given a string, reverse the words in the string.
    Ex: "This is a string" -> "string a is This"

**/

/**
    Run-time Complexity: O(n)
    Space Complexity: O(1)
**/

#include<iostream>

using namespace std;

void reverseWords(string& str,int startIndex, int endIndex){

    while(startIndex < endIndex){
        swap(str[startIndex],str[endIndex]);
        startIndex++;
        endIndex--;
    }
}

void reverseString(string& str){

    //reverse the entire string: This is -> si sihT
    reverseWords(str,0,str.length()-1);

    //reverse the words in the reversed string: si sihT -> is This
    int startIndex = 0;
    for(int currIndex = 0; currIndex <=str.length()-1; currIndex++){
        //if you find end of the word or space
        if(currIndex == str.length()-1){
            reverseWords(str,startIndex,currIndex);
        } else if (str[currIndex] == ' '){
            reverseWords(str,startIndex,currIndex-1);
            startIndex = currIndex+1;
        }
    }
}

int main(){
    string str = "This is a string";
    cout<<"Input string:"<<str<<endl;
    reverseString(str);
    cout<<"Modified string:"<<str<<endl;
    return 0;
}

/****
    1. Difference between '' and "" in C/C++
    ' ' - int type(ASCII) - character literal -
    " " - string type - a pointer
*/
