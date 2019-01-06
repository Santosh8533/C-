/**
    Author: Santosh Tandrothu
    Date:1/6/2019 Sunday
    Problem: Build a queue using two stacks

**/
/**
    Run-time: O(n) --- (calculated using accounting method: cost incurred by each item not by each operation)
    Space: O(1)
**/
#include<iostream>
#include<stack>

using namespace std;

class Dequee{

private:
    stack<int> inStack;
    stack<int> outStack;

public:
    void enquee(int val){
        inStack.push(val);
    }

    void dequee(){
        if(inStack.empty() && outStack.empty())return;

        if(outStack.empty()){
            while(!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
            outStack.pop();
        }

        else{
            outStack.pop();
        }
    }

    void checkResult(){
      if(inStack.empty() && outStack.empty()){return;}

            while(!outStack.empty()){
            cout<<outStack.top()<<endl;
            outStack.pop();
            }

            while(!inStack.empty()){
                outStack.push(inStack.top());
                inStack.pop();
            }
            while(!outStack.empty()){
            cout<<outStack.top()<<endl;
            outStack.pop();
            }

    }

};

int main(){

    Dequee que;
    que.enquee(1);
    que.enquee(2);
    que.enquee(3);
    que.dequee();
    que.enquee(4);
    que.enquee(5);
    que.dequee();
    que.checkResult();
    return 0;
}
