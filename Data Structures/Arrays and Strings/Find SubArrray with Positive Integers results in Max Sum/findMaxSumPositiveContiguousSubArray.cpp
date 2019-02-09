/**
    Author: Santosh Tandrothu
    Date: 02/08/2019
    Problem: Find out the contiguous sub-array of non negative numbers that results in maximum sum from a given array.
             Ex: A : [1, 2, 5, -7, 2, 3]
             The two sub-arrays are [1, 2, 5] [2, 3].
             The answer is [1, 2, 5] as its sum is larger than [2, 3]

**/

/**
    Time-Complexity: O(n)
    Space-Complexity: O(1)
**/

#include<iostream>
#include<vector>

using namespace std;

vector<int> findMaxSumPositiveContiguousSubArray(const vector<int> &nums){

    //for results
    vector<int> res;
    int startIndex;
    int endIndex;

    //for tracking the sum
    int currStart = 0;
    int currEnd = 0;
    int currSum = 0;
    int maxSum = 0;

    while(currEnd<nums.size()){

        //if positive - add elements to the sum
        if(nums[currEnd] > 0){
            currSum+= nums[currEnd];
        }
        //if negative - reset the sum and current start
        else{
            if(maxSum < currSum){
                maxSum = currSum;
                //reset or set the start and end indices
                startIndex = currStart;
                endIndex = currEnd-1;
            }

            currSum = 0;
            currStart = currEnd+1; //move the start to next element
        }
        currEnd++;
    }

    //to cover [2,8] case: [1, 2, 5, -7, 2, 8]

    if(maxSum < currSum){
                maxSum = currSum;
                //reset or set the start and end indices
                startIndex = currStart;
                endIndex = currEnd-1;
    }

    //update results
    for(int i=startIndex;i<=endIndex;i++){
        res.push_back(nums[i]);
    }

    return res;
}

int main(){
    vector<int> v={1, 2, 5, -7, 2, 4};
    //vector<int> v={1,5,2,3,4};
    cout<<"Run-time: O(N):"<<endl;
    vector<int> output = findMaxSumPositiveContiguousSubArray(v);
    cout<<"[";
    for(int i:output){
        cout<<i<<"\t";
    }
    cout<<"]";
}
