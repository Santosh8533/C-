    /**
        Author: Santosh Tandrothu
        Date: 01/24/2019
        Problem: Given a simulated 5-sided die, develop a 7-sided die using 5-sided die.
        Aim for uniform distribution or equal probability of occurence.
    **/

    /***
        Time Complexity = O(∞) (There is a chance for the die to keep re-rolling forever)
        Space Complexity = O(1)
    **/

#include <iostream>
#include <random>

using namespace std;

int rand5()
{
    static random_device rd;
    static mt19937 g(rd());
    static uniform_int_distribution<int> d(1, 5);
    return d(g);
}

int rand7(){

    while(true){
        int roll1 = rand5();
        int roll2 = rand5();

        //Generates ---(roll1-1)*5=for each row (5,10,15,20,25)
        //Generates ((roll2-1)+1)=1,2,3,4,5 for each column
        int outcomeNumber = (roll1-1)*5 + ((roll2-1)+1);

        if(outcomeNumber > 21) {
            continue;
        }

        return outcomeNumber%7+1;
    }
    return 0;
}

int main()
{
    for (int i = 0; i < 14; ++i) {
        cout << rand7() << ' ';
    }
    cout << endl;

    return 0;
}
