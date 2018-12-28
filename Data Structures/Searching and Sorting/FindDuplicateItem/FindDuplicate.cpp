/***
Author: Santosh Tandrothu
Date: 12/24/2018
Problem: Given a list of integers size N+1 with N unique integers , find the duplicate item in the list.
Example: {2,4,3,5,5,1} -> 5
***/

/**
Run-time complexity: O(nlogn)
Space complexity: O(1)
**/

#include<iostream>
#include<vector>

using namespace std;

int findRepeat(const vector<int>& inputNumbers){
	int start_ = 1; 
	int end_ = inputNumbers.size()-1;	
	
	while(start_ < end_){
		int mid = start_ + (end_-start_)/2; 
		
		int lowerRangeStart = start_; 
		int lowerRangeEnd = mid; 
	
		int upperRangeStart = mid+1; 
		int upperRangeEnd = end_; 
		
		int itemsInlowerRange = 0;
		
		for(int i:inputNumbers){
			if(i>=lowerRangeStart && i<=lowerRangeEnd){
				itemsInlowerRange++;
			}
		
			int idealItemsInLowerRange = lowerRangeEnd-lowerRangeStart + 1;
			
			if(itemsInlowerRange > idealItemsInLowerRange){
				start_ = lowerRangeStart;
				end_ = lowerRangeEnd;
			}
			else {
				start_ = upperRangeStart;
				end_ = upperRangeEnd;
			}
		}
	}
	return start_;
}

int main(){
	
	vector<int> inputNumbers = {1,2,3,4,5,5};
	int repeatedNumber = findRepeat(inputNumbers);
	cout<<"The repeated number is:"<<repeatedNumber<<endl;
	return 0;
}
