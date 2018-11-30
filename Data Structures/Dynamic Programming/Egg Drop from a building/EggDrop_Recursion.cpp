#include<iostream>
#include<limits.h>

using namespace std;

int min_(int a,int b){
    return (a<b)?a:b;
}

int max_(int a, int b){
    return (a>b)?a:b;
}


int minEggDroppings(int eggs,int floors){

    //base conditions
    if(eggs == 1){return floors;}
    if(floors == 0 || floors ==1){return floors;}

    int minimum = INT_MAX;

    for(int floor=1;floor<=floors;floor++){
        minimum = min_(minimum,1+max_(minEggDroppings(eggs-1,floor-1),minEggDroppings(eggs,floors-floor)));
    }
    return minimum;
}
int main(){
    int eggs = 3;
    int floors = 20;

    cout<<"Worst Case: Minimum egg droppings are:"<<minEggDroppings(eggs,floors);
}
