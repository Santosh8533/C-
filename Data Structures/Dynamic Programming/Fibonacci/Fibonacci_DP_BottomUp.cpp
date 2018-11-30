#include<iostream>
#include<vector>

using namespace std;


/**
    Run-time: O(n)
    Space: O(1)
***/

int getFibonacciNumberBottomUpConstSpacComp(int target){
    //initialize
    //n-1
    int elementN_1 = 1;
    //n-2
    int elementN_2 = 0;

    int currentEle = 0;
    for(int i=2;i<=target;i++){
        currentEle = elementN_1 + elementN_2;
        elementN_2 = elementN_1;
        elementN_1 = currentEle;
    }
    return currentEle;
}


/**
    Run-time: O(n)
    Space: O(h) h-height of the recursion tree: In this case it's "n" -> O(n)
***/

int getFibonacciNumberBottomUp(int target, vector<int>& lookup){
    //initialize
    lookup[0] = 0;
    lookup[1] = 1;

    for(int i=2;i<=target;i++){
        lookup[i] = lookup[i-1] + lookup[i-2];
    }
    return lookup[target];
}

int main(){
    cout<<"What is the fibonacci number that you are looking for:";
    int target;
    cin>>target;
    //initialize target+1 locations to zeroes
    vector<int> lookup(target+1);
    cout<<getFibonacciNumberBottomUp(target,lookup)<<"\t";
    cout<<getFibonacciNumberBottomUpConstSpacComp(target);
    return 0;
}
