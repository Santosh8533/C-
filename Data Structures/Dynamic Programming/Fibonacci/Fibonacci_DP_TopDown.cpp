#include<iostream>
#include<vector>

using namespace std;
/**
    Run-time: O(n) - once all the n values lookup were calculated, then everything else is a simple lookup
    Space: O(h) h-height of the recursion tree: In this case it's "n" -> O(n)
***/

int getFibonacciNumberMemo(int target, vector<int>& lookup){
    //brake
    if(target == 0 || target ==1){lookup[target]=target; return target;}

    //look for current number
    //if present
    if(lookup[target]!=0)return lookup[target];

    //if not present
    else{
        lookup[target] = getFibonacciNumberMemo(target-1,lookup) + getFibonacciNumberMemo(target-2,lookup);
    }
    //engine
    return lookup[target];
}

int main(){
    cout<<"What is the fibonacci number that you are looking for:";
    int target;
    cin>>target;
    vector<int> lookup(target+1); //initialize target+1 locations to zeroes
    //cout<<lookup[0]<<" " <<lookup[1]<<endl;
    cout<<getFibonacciNumberMemo(target,lookup);
    return 0;
}
