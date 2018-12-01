/***
    Author: Santosh Tandrothu
    Date: 11/12/2018
	Given a set of coins and a amount, find the no of possible denominations by the coins
	Ex: Amount = 5 Coins = {1,3,5}
	Answer: 3 -> {11111,113,5}
***/

/***
    Time Complexity = O(coins * amount) = O(n*k)
    Space Complexity = O(amount) = O(n)
***/

#include<vector>
#include<iostream>

using namespace std;

size_t getNoOfPossibleDenominations(int amount,const vector<int>& coins){
//	if(amount==0 || coins.size() ==0) throw invalid_argument(“Enter valid amount or coins”);

	vector<size_t> lookup(amount+1);
	lookup[0] = 1;//This is to cover the case when a coin is selected equal to its amount

// Select all coins one by one
	for(const int coin:coins){
        // Build the lookup table for amounts for every coin
        for(int currAmount = coin;currAmount<=amount;currAmount++){
            int remAmount = currAmount - coin;
            lookup[currAmount] = lookup[currAmount] + lookup[remAmount];
            //cout<<currAmount<<":->"<<lookup[coin]<<endl;
        }
    }
    return lookup[amount];
}

int main(){
	vector<int> coins = {1,3,5};
	int amount = 5;
	cout<<"No of possible denominations for the given amount:"<<amount<<"->"<<getNoOfPossibleDenominations(amount,coins);
}
