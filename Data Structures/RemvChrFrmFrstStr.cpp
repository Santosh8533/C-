/**

    Author: Santosh Tandrothu
    Date: 09/15/2018

    Problem: Remove characters from the first string which are present in the second string
    Example: first_string = "GeeksforGeeks" second_string="mask"
    Result: GeeforGee

    Exception: When the last char in a string is deleted using erase function, it2 is pointing to some random value which throws an exception
    Fix: Save the previous value in temp - 99 - Once the current value is deleted - 100 - pointer goes back to 99 in normal case -
    but in worst case if it is the last element - it2 = temp saves us from causing this exception

    New things learnt:
    1. New way of iterating over the vector
    vector<int> v ={1,2,3};
    for (int x : v)
    cout << x << " ";
**/

#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

void RemChrFrmFrstStr(string &str, string second_str)
{
    //if empty
    if (str.empty()){cout<<"String is empty"<<endl;return;}
    string::iterator it1,it2,temp;
    for(it1=second_str.begin();it1!=second_str.end();it1++){
        //cout<<*it1<<endl;;
        for(it2=str.begin();it2!=str.end();it2++){
           //cout<<*it2;
            if(*it1 == *it2){
                temp = it2-1;; //99 - to save the previous location to prevent exception
                str.erase(it2); //100
                it2 = temp; //99 - loading temp value into it2 again to prevent exception
            }
        }
    }
}

int main(){
    string str{"GeeksforGeeks"};
    string second_str{"mask"};
    cout<<str<<endl;

    RemChrFrmFrstStr(str,second_str);

    cout<<str<<endl;
    return 0;
}

