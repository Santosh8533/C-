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

size_t changePossibilities(int amountLeft,
        const vector<int>& denominations,
        size_t currentIndex = 0)
{

    // base cases:
    // we hit the amount spot on. yes!
    if (amountLeft == 0) {
        return 1;
    }

    // we overshot the amount left (used too many coins)
    if (amountLeft < 0) {
        return 0;
    }

    // we're out of denominations
    if (currentIndex == denominations.size()) {
        return 0;
    }

    cout << "checking ways to make " << amountLeft << " with [";
    for (size_t i = currentIndex; i < denominations.size(); ++i) {
        if (i > currentIndex) {
            cout << ", ";
        }
        cout << denominations[i];
    }
    cout << "]" << endl;

    // choose a current coin
    int currentCoin = denominations[currentIndex];

    // see how many possibilities we can get
    // for each number of times to use currentCoin
    size_t numPossibilities = 0;
    while (amountLeft >= 0) {
        numPossibilities += changePossibilities(amountLeft,
            denominations, currentIndex + 1);
        amountLeft -= currentCoin;
    }

    return numPossibilities;
}


int main(int argc, char** argv)
{
    cout<<changePossibilities(4,{1,2,3});
    //return lest::run(tests, argc, argv);
}
