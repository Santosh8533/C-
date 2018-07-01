        /**
            Author: Santosh Tandrothu
            Date: 06/30/2018
            Problem: Given a string and regEx pattern, return true if string matches
            the pattern
                '*' - represents zero or more preceding elements
                '.' - represents any single character
            Algorithm:
                1. Traverse the string (k++) and regEX(i++) simultaneously
                2. Based on the regEx symbol, increment the pointers(k & i) appropriately.
        **/

        /***
            Time Complexity = O(n) (Traversing the string and regex simulataneously)
            Space Complexity = O(1)
        **/

#include<iostream>

using namespace std;

bool isMatch(string str,string regEx){

    char c,prev;
    int j=0,k=0;
    for(int i=0;i<regEx.length();i++){
        c = regEx[i];
        switch(c){

            case '.':
            //Any character is fine except space
                if(str.at(k)==' '){return false;}
                prev = str.at(k);
                k++;
                break;

            case '*':
                for(j=k;j<str.length();j++){
                    if(str[j] != prev){
                        break;
                    }
                    k++;
                }
                prev = str.at(k-1);
                //i = j;
                break;

            default:
            if(str[k]!=regEx[i]){return false;}
            prev = str.at(k);
            k++;

        }

    }
    return true;
}




int main(){
    string str = "saaabaan";
    string regEx = "s.*ba*n";
    //sa*n
    cout<<"Match found?"<<isMatch(str,regEx);

}
