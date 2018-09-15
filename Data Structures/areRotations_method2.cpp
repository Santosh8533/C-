    /**
        Author: Santosh Tandrothu
        Date: 09/15/2018
        Problem: Given two string,find if they are rotations of each other

        Ex: s1= "abcd" s2 = "cdab"
        Rotations of s1 = abcd
                          dabc
                          cdab
                          bcda
        Output: Yes! s2 is a rotation of s1
    **/

    /***
        Time Complexity = O(n)
        Space Complexity = O(1)
    **/

#include<iostream>
#include<iterator>
#include<string>

using namespace std;

bool areRotations(string s1,string s2){

    //check if sizes of two string are same
    if(s1.length()!=s2.length())return false;

    //take a temp string and combine both of them
    string temp = s1+s1;
    //Find if s2 exists as a substring

    return (temp.find(s2)!=string::npos);
}

int main(){
    string s1="ABCD", s2 = "CDAB";
    if(areRotations(s1,s2)){
        cout<<"s1 and s2 are rotations of each other"<<endl;
    }
    else cout<<"s1 and s2 are not rotations of each other"<<endl;
}
