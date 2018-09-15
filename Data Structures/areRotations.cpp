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

using namespace std;

bool areRotations(string s1,string s2){

    //check if sizes of two string are same
    if(s1.length()!=s2.length())return false;

    //Take two pointers to point to s1 and s2 each
    int s1_p=0, s2_p=0;

    int len = s1.length();

    while(s2_p!=len){
        //find first element and break the while loop
        if(s1[s1_p]==s2[s2_p]){break;}
        s2_p++;
    } //s1_p = 0 s2_p=2

    //if element is not found
    if(s2_p==len){return false;}

    //position found - increment s1_p and s2_p

    while(s1_p!=len-1){
            s1_p++; //s1_p = 1;
            s2_p++; //s2_p = 3;
            if(s2_p==len){s2_p=0;}
            if(s1[s1_p]!=s2[s2_p]){return false;}
    }
    return true;
}

int main(){
    string s1="ABCD", s2 = "CDAB";
    if(areRotations(s1,s2)){
        cout<<"s1 and s2 are rotations of each other"<<endl;
    }
    else cout<<"s1 and s2 are not rotations of each other"<<endl;
}
