/**
    Run-time: O(2^n)
    Space: O(h) h-height of the recursion tree: In this case it's "n" -> O(n)
***/

#include<iostream>

using namespace std;

int getFibonacciNumber(int target){
    //brake
    if(target == 0 || target ==1){return target;}

    //engine
    return getFibonacciNumber(target-1) + getFibonacciNumber(target-2);
}

int main(){
    cout<<"What is the fibonacci number that you are looking for:";
    int target;
    cin>>target;
    cout<<getFibonacciNumber(target);
    return 0;
}
