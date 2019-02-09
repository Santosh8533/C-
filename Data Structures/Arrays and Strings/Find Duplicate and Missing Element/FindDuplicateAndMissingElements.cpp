/**
    Author: Santosh Tandrothu
    Date: 02/07/2019
    Problem: Given a array of unsorted integers of size n, integers ranging from 1 to n with a number repeated twice.
    find the repeated number and missing number
**/


/**
    1. QUICKSORT: 1,2,3,3,5 - nlogn
    2. Traversal: found 3 as repeated and 4 is missing -O(n)
    3. Total:nlogn
**/

/**
    1. 4,2,3,1,3
    2. Declare a new vector - bool type
    3. Traverse through the array and set the new vector
    4. if it is already set - it is the repeated element
    5. Traverse and find the element which is not set
**/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> findDuplicateAndMissingElementsN(vector<int> input){
    vector<bool> output(input.size());

    for(int i=0;i<input.size();i++){
        output[i]= false;
    }

    vector<int> res;
    int repeated=-1;
    int missing=-1;

    //checking repeated number
    for(int i=0;i<input.size();i++){
        int current = input.at(i);
        if(output.at(current-1)){repeated = current;}
        output.at(current-1) = true;
    }

    //checking missing number
    for(int i=0;i<output.size();i++){
        if(!output.at(i)){
                missing = i+1;
                res.push_back(missing);
                res.push_back(repeated);
                return res;
        }
    }

    //if there are no duplicates
    res.push_back(missing);
    res.push_back(repeated);
    return res;
}

vector<int> findDuplicateAndMissingElementsNLogN(vector<int> input){
    sort(input.begin(),input.end());
    vector<int> res;
    for(int i=0;i<input.size()-1;i++){
        if(input.at(i) == input.at(i+1)){
            res.push_back(input.at(i+1)+1);
            res.push_back(input.at(i));
            return res;
        }
    }
    return res;
}

int main(){
    vector<int> v={3,1,5,2,3};
    //vector<int> v={1,5,2,3,4};
    cout<<"Run-time: O(NlogN):"<<endl;
    vector<int> output = findDuplicateAndMissingElementsNLogN(v);
    for(int i:output){
        cout<<i<<endl;
    }
    cout<<"Run-time: O(N):"<<endl;
    vector<int> output1 = findDuplicateAndMissingElementsN(v);
    for(int i:output1){
        cout<<i<<endl;
    }
}
