
    /**
        Author: Santosh Tandrothu
        Date: 11/29/2018
        Problem: Given set of cakes and a capacity that could fit in a duffel bag, return
                 max value of cakes that fits the capacity
    **/

    /***
        Time Complexity = O(cakes * capacity)
        Space Complexity = O(capacity)
    **/


#include<iostream>
#include<vector>
//#include<algorithm> //max

using namespace std;

class CakeType{
public:
    const unsigned int weight_;
    const unsigned int value_;

    CakeType(unsigned int weight=0, unsigned int value=0):
        weight_(weight),
        value_(value)
        {
        }
};

int maxDuffelBagValue(vector<CakeType> cakeTypes,unsigned int capacity)
{
    //lookup table
    vector<unsigned long long> maxValueAtCapacity(capacity+1);

    //calculate max for all capacities
    for(unsigned int cap=0;cap<=capacity;cap++){
        //for each capacity - try all cakes - pick the max for each capacity
        unsigned long long currentCapacity = 0;
        for(const CakeType& cakeType:cakeTypes){
            unsigned long long maxValueAtCapacityUsingACake = cakeType.value_ + maxValueAtCapacity[capacity-cakeType.weight_];
            currentCapacity = max(maxValueAtCapacityUsingACake,currentCapacity);
        }
        maxValueAtCapacity[capacity]=currentCapacity;
    }

    return maxValueAtCapacity[capacity];
}
int main(){

    const vector<CakeType> cakeTypes{
        CakeType(7,160),
        CakeType(3,90),
        CakeType(2,15)
    };
    // 7kgs cake that costs 160 dollars

    unsigned int capacity = 20;

    cout<<"Max value of the cakes that fits in duffel bag:"<<maxDuffelBagValue(cakeTypes, capacity);
}
