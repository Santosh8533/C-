/**
    Run: O(eggs*floors)
    Space: O(eggs*floors)
**/

#include<iostream>
#include<limits.h>


using namespace std;



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
int minEggDroppings(int eggs,int floors){


    //create a lookup
    int lookup[eggs+1][floors+1];

    //initialize the lookup
    //initialize the zero row with 0's
    for(int i=0;i<=floors;i++){lookup[0][i]=0;}
    //initialize the 1st row with no of floors: With 1 egg it takes atleast "no of floors" trials
    for(int i=1;i<=floors;i++){lookup[1][i]=i;}
    //initialize the zero column  with 0's
    for(int i=0;i<=eggs;i++){lookup[i][0]=0;}

    //for each nu of eggs and respective floors - build the lookup
    //ex: lookup[2eggs][1 floor] = min(lookup[2eggs][1 floor],1+max(lookup[2eggs-1][1 floor-1],lookup[2eggs][totalfloors - 1 floor],

    for(int currEggs=2;currEggs<=eggs;currEggs++){
        for(int floors_=1;floors_<=floors;floors_++){
        //Above two loops are to fill the lookup table
        //Below loop is to cover all the floors and pick the minimum attempts
        //select each floor to drop an egg and calculate the best outcome which is minAttempts
            int minimum= INT_MAX;
            for(int currFloor=1;currFloor<=floors_;currFloor++){
                //if egg breaks->cover "floor-1" floors with "eggs-1" eggs
                int eggBreakAttempts = lookup[currEggs-1][currFloor-1];
                //if egg doesn't break->cover "floors - floor" floors with "eggs" eggs
                int eggDoesNotBreakAttempts = lookup[currEggs][floors_-currFloor];
                //worstcase attempts - 1 indicates an attempt which results in break or non-break attempts
                int noOfAttemptsWorstCase = 1+max(eggBreakAttempts,eggDoesNotBreakAttempts);
                //Get currentMin
                minimum = min(minimum,noOfAttemptsWorstCase);
            }
        //once all floors are selected and got the minimum value-update lookup
        lookup[currEggs][floors_] = minimum;
        //cout<<lookup[currEggs][floors_]<<" ";
        }
        //cout<<endl;
    }

    //cout<<"\nArray:\n\n";

    //Prints lookup
    for(int i=0;i<=eggs;i++){
        for(int j=0;j<=floors;j++){
            cout<<lookup[i][j]<<" ";
        }
        cout<<"\n";
    }

    return lookup[eggs][floors];
}
int main(){
    int eggs = 2;
    int floors = 5;
    cout<<"Number of trials in the worst case using the best strategy:"<<minEggDroppings(eggs,floors);

}

