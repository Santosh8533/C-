    /**
        Author: Santosh Tandrothu
        Date: 11/12/2018
        Problem: Given an set of coins and amount, calculate no of ways to find amount
        using giving coins
    **/

    /***
        Time Complexity =
        Space Complexity =
    **/

#include <iostream>
#include <vector>

// C++11 lest unit testing framework

using namespace std;

size_t changePossibilities(int amount,
        const vector<int>& denominations)
{
    vector<size_t> waysofDoingNCents(amount+1); //vector of zeroes from 0..amount
    waysofDoingNCents[0] = 1;

    for(const int coin:denominations){
        for(int incrementalAmount=coin;incrementalAmount<=amount;incrementalAmount++){
            waysofDoingNCents[incrementalAmount]+= waysofDoingNCents[incrementalAmount-coin];
        }
    }

    return waysofDoingNCents[amount];
}



int main(int argc, char** argv)
{
    cout<<changePossibilities(4,{1,2,3});
    //return lest::run(tests, argc, argv);
}
