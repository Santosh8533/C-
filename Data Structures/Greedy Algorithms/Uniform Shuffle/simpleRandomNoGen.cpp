/**
    rand()-returns any integer value between 0 and at least 32767
**/

#include<iostream>
#include<ctime> //std::time
#include<cstdlib> //std::rand and srand

using namespace std;

void genSpecificRanNum(int min_, int max_){
    srand(time(0));
    for(int i=0;i<5;i++){
        cout<<(rand()%max_) + 1<<endl;
    }
}

int main(){
    cout<<"Generating random numbers:"<<endl;
    //seeding the random no generator - do this only once
    srand(time(0));
    for(int i=0;i<5;i++){
        cout<<rand()<<endl;
    }

    //generate random numbers between 1 and 99
    genSpecificRanNum(1,10);
}
