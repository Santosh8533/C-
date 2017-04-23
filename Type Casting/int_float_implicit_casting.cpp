#include<iostream>

using namespace std;

int main(){
    int i=4;
    float j=5.1;
    cout<<"Hello World";
    auto x=i- j;  //auto should be always initialized
    cout<<"Result:"<<x<<endl;
return 0;
}

/*if the result x is integer auto becomes integer.
    j=5.0 x=5 The result is 0. So auto becomes integer
else the result x is float, auto becomes float.
    i=5 j=5.1 The result is -0.1. So auto becomes float.
Note: int is unsigned by default. To make it signed, add signed keyword before it.
    */
