    /**
        Author: Santosh Tandrothu
        Date: 01/19/2019
        Problem: Given a vector of 1...n numbers with one repeated number, find and
        return it
    **/

    /***
        Time Complexity = O(n)
        Space Complexity = O(1)
    **/


#include<iostream>
#include<vector>
#include<stdexcept>

using namespace std;

unsigned int getRepeatedNumber(const vector<unsigned int>& numbers){

    if (numbers.size() < 2) {
        throw invalid_argument("Finding duplicate requires at least two numbers");
    }

    unsigned int repeatedNumber=0;
    unsigned int sumWithoutDuplicate=0;
    unsigned int actualSum=0;

    unsigned int n = numbers.size()-1;
    sumWithoutDuplicate = (n*n+n)/2;

    for(unsigned int i=0;i<numbers.size();i++){
        actualSum += numbers.at(i);
    }

    repeatedNumber = actualSum - sumWithoutDuplicate;

    return repeatedNumber;
}



int main(){
     vector<unsigned int> numbers = {1,2,3,4,3,5};
     cout<<"Repeated Number is:"<<getRepeatedNumber(numbers)<<endl;
}
