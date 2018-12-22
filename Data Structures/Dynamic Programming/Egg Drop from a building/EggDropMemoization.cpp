#include<iostream>
#include<limits.h>
#include<unordered_map>

using namespace std;

int min_(int a,int b){
    return (a<b)?a:b;
}

int max_(int a, int b){
    return (a>b)?a:b;
}

/***
    for each floor -> calculate no of min egg droppings
        Ex: 1st floor with 2 eggs -> 1 dropping
            2nd floor with 2 eggs -> 2 droppings
            3rd floor with 2 eggs -> 2 droppings
                -> (Start from 3rd floor: It takes 3 droppings to test- but you have only 2 eggs)
                -> (Start from 2nd floor: It takes 2 droppings to test- and you have only 2 eggs)
                -> (Start from 1st floor: It takes 3 droppings to test- but you have only 2 eggs)
                -> (Answer: Out of the above 3 - min droppings - 2 can be achieved when 2nd floor is selected first)

***/

//Array bound is not an integer constant before ']' token: ERror popped when returning
int minEggDroppings(int eggs,int floors,int lookup){


    //base conditions
    if(eggs == 1){return floors;}
    if(floors == 0 || floors ==1){return floors;}

    int  minimum = 0;
    //search in lookup
    for(int floor=1;floor<=floors;floor++){

        if(lookup[eggs][floor]!=0){
            return lookup[eggs][floor];
        }

        else {
                lookup[eggs][floor] = min_(lookup[eggs][floor],1+max_(minEggDroppings(eggs-1,floor-1,lookup),minEggDroppings(eggs,floors-floor,lookup)));
            }
    }//end of for loop

    return lookup[eggs][floors];
}
int main(){
    int eggs = 3;
    int floors = 20;
    unordered_map<pair<int,int>,int> lookup;
    //int minimum = minEggDroppings(eggs,floors,lookup);
    cout<<"Worst Case: Minimum egg droppings are:"<<minimum;
    //look into the below line later
    //cout<<"Worst Case: Minimum egg droppings are:"<<minEggDroppings(eggs,floors,lookup);
}

