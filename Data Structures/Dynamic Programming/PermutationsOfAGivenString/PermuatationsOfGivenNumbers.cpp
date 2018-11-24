/**Notes
    1. Thought: Select an element from the string. Mark it as selected. Add it to temp string.
                Repeat the same process for rest of the chars. Add the curr string to permutations when
                length of the current string is equal to input string.
                Deselect an element from the current string and repeat the same process.

**/
    /**
        Author: Santosh Tandrothu
        Date: 11/24/2018
        Problem: Given a string, generate all the possible permutations
    **/

    /***
        Time Complexity = O(n!)
        Space Complexity = O(n!)
    **/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<iterator>

using namespace std;

void permutateNumbersUtil(unordered_map<int,bool>& numbers,
                      vector<vector<int>>& permutations,
                      vector<int>& currentPermutation,
                      int noOfSelectionsRem){

    //If there are numbers to select
    if(noOfSelectionsRem == 0) {permutations.push_back(currentPermutation); return;}

    unordered_map<int,bool>::iterator it;
    for(it=numbers.begin();it!= numbers.end();it++){
        if(it->second == true){ //select the number
            currentPermutation.push_back(it->first);
            it->second = false; //Mark it as selected
            permutateNumbersUtil(numbers,permutations,currentPermutation,noOfSelectionsRem-1); //Recurse
            it->second = true; //Unselect the number to make it available for the next permutation
            currentPermutation.pop_back(); //Pop the number from current permutation
        }
    }
}

void permutateNumbers(unordered_map<int,bool>& numbers,vector<vector<int>>& permutations){
    int noOfSelectionsRem = numbers.size();
    vector<int> currentPermutation;
    permutateNumbersUtil(numbers,permutations,currentPermutation,noOfSelectionsRem);
}

int main(){
    unordered_map<int,bool> numbers = {{1,true},
                                       {2,true},
                                       {3,true},
                                       {4,true},
                                       {5,true}};
    vector<vector<int>> permutations;
    permutateNumbers(numbers,permutations);

    vector<vector<int>>::iterator it;
    vector<int>::iterator vit;

    cout<<"Total no of permutations:"<<permutations.size()<<"\n";
    for(it=permutations.begin();it!=permutations.end();it++){
        for(vit=it->begin();vit!=it->end();vit++){
            cout<<*vit;
        }
        cout<<"\n";
    }

}
