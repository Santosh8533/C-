/**
        Author: Santosh Tandrothu
        Date: 09/13/2018
        Problem: Given a string, find the maximum occuring character in the string


        Time Complexity = O(n)
        Space Complexity = O(1) (constant space as the hashing array size of ALPHABET_SIZE)

    Errors: Random max occuring character -> When array not initiliazed, the garbage values remained in the array
    and those are incremented when the program is executed

**/


#include<iostream>
#include<string.h>
#define ALPHABET_SIZE 256 //covering all ASCII characters
using namespace std;

char getMaxOccuringChar(char *str){

    //Hash
    int charCount[ALPHABET_SIZE];
    for(int i=0;i<ALPHABET_SIZE;i++){
       charCount[i] = 0;
       //cout<<charCount[i]<<endl;
    }

    //Iterate over the string
    int len = strlen(str);
    int maxOccur = 0, maxOccurIndex = -1;
    for(int i=0;i<len;i++){
        charCount[str[i]]++;
        //cout<<"Char:->"<<str[i]<<endl;
        //cout<<"CharCount:->"<<charCount[str[i]]<<endl;
        if(charCount[str[i]] > maxOccur){
            maxOccur = charCount[str[i]];
            maxOccurIndex = i;
            //cout<<"maxOccur:->"<<maxOccur<<endl;
            //cout<<"maxOccurIndex:->"<<maxOccur<<endl;
        }
    }

    return str[maxOccurIndex];
}

int main(){
    char str[] = "sample stringgg";
    cout<<"Max occuring character is:"<<getMaxOccuringChar(str);
}
