#include<iostream>

using namespace std;

int main(){
    int i=4;
    double j=5.1; //if j is 5.0, the .0 is ignored
    auto x=i- j;  //auto should be always initialized
    cout<<"J="<<j<<endl;
    cout<<"Result:"<<x<<"size:"<<sizeof(x)<<endl;
return 0;
}

/*if the result x is integer auto becomes integer.
    j=5.0 x=5 The result is 0. So auto becomes integer
else the result x is float, auto becomes float.
    i=5 j=5.1 The result is -0.1. So auto becomes float.
Note: int is unsigned by default. To make it signed, add signed keyword before it.
    */
/*Type conversion rules:
    1) If eithe operand is double, the other operand becomes double
    2) If either operand is float, the other operand becomes float.
    http://stackoverflow.com/questions/5563000/implicit-type-conversion-rules-in-c-operators*/
