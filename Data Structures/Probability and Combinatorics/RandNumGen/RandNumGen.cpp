    /**
        Author: Santosh Tandrothu
        Date: 01/20/2019
        Problem: Given a rand7() which generates 1 to 7 with equal prob, design rand5()
        utilizing rand7() to generate 1 to 5 with equal probability
    **/

    /***
        Time Complexity = O(infinity) - loop might never end
        Space Complexity = O(1)
    **/
#include<iostream>
#include<cstdlib>
#include<random>

using namespace std;



int rand7()
{
    static random_device rd;
    static mt19937 g(rd());
    static uniform_int_distribution<int> d(1, 7);
    return d(g);
}

void rand5_iter(){
    int num = 7;
    while(num>5){
        num =rand7();
    }
    return num;
}

int main(){
    rand5_iter();
}
