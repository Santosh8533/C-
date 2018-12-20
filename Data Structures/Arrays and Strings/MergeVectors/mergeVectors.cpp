/**
	Author: Santosh Tandrothu
	Date: 12/19/2018
	Problem: Alice and Bob want to win the scouts cookies contest and agreed to combine their cookie sales.
	Given their cookie sales in sorted order, merge their sales in a sorted order
	Example: Alice's Sales = {1,3,5} Bob's Sales = {2,4,6} MergedSales = {1,2,3,4,5,6}
**/

/**
	Run-time complexity: O(n) - iterating through all alice's and bob's cookies once
	Space-time complexity: O(n) - vector to store the merged results
**/

#include<iostream>
#include<vector>

using namespace std;

vector<int> mergeCookies(vector<int>& v1, vector<int>& v2){
    //if v1-empty - return v2
    if(v1.size()==0) return v2;
    //if v2-empty - return v1
    else if(v2.size()==0) return v1;
    //Create a mergedVector
    vector<int> merged;
    //cout<<merged.size()<<endl;

    //compare the two loops sizes and pick the shortest
    //When the shortest gets traversed, push all the remaining elements in the longest to the merged vector
    int count_;
    if(v1.size()<=v2.size()){count_=v1.size();}
    else count_=v2.size();
    int i=0,j=0;
    while(i<count_ && j<count_){
        if(v1[i] < v2[j]){
                merged.push_back(v1[i]);
                i++;
        }
		else if(v1[i] == v2[j]){
			merged.push_back(v1[i]);
			i++; j++;
		}
        else {
            merged.push_back(v2[j]);
            j++;
        }
    }

    while(i<v1.size()){
        merged.push_back(v1[j]);
        i++;
    }

    while(j<v2.size()){
        merged.push_back(v2[j]);
        j++;
    }
    //return merged vector
    return merged;
}

int main(){

    vector<int> aliceCookies = {1,3,5};
    vector<int> bobCookies = {2,4,6,8,10};
    vector<int> mergedCookies = mergeCookies(aliceCookies,bobCookies);

    for(int i:mergedCookies){
        cout<<i<<endl;
    }

    return 0;
}

