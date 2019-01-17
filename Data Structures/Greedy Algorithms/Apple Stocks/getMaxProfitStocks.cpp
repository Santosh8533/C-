    /**
        Author: Santosh Tandrothu
        Date: 01/16/2019
        Problem: Find the maximum profit by finding right buying and selling
                 price from apple stocks which are listed in a vector with
                 their time as indices. Base time: 9:00AM. Each index represents 1 minute.
    **/

    /***
        Time Complexity = O(n)
        Space Complexity = O(1)
    **/

#include<iostream>
#include<vector>
#include<stdexcept>

using namespace std;
/*1. start from first stock - maintain minimum value - max profit
    2. Iterate over other prices and update the step 1 values accordingly -
        return profit at the end*/

int getMaxProfitStocks(const vector<int>& stocks){

    //no stock prices at all
    if(stocks.size()==0){
        throw invalid_argument("Stock prices empty");
    }

    if(stocks.size()<2){
        throw invalid_argument("There should be more than two stock prices");
    }


    int minBuyingPrice = stocks.at(0);
    //initializing the profit considering first two prices
    int maxProfit = stocks.at(1) - stocks.at(0);

    for(int i=1;i<stocks.size();i++){

            int currentSellPrice = stocks.at(i);

            int currentProfit = currentSellPrice - minBuyingPrice;
            //update maxProfit
            maxProfit = max(currentProfit,maxProfit);

            //find minimum price
            minBuyingPrice = min(minBuyingPrice, currentSellPrice);

    }

    return maxProfit;
}



int main(){
    vector<int> stocks = {3,6,8,9,1,8};
    cout<<"Profit is:"<<getMaxProfitStocks(stocks)<<endl;

    //prices go down all day - return least possible loss
    //expected = -1 (Buying price = 4, selling price=3)
    vector<int> stocks1 = {7,4,3,1};
    cout<<"Profit is:"<<getMaxProfitStocks(stocks1)<<endl;

}
