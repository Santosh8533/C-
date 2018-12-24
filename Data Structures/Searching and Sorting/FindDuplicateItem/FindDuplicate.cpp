#include<iostream>

using namespace std;

int findRepeat(const vector<int>& inputNumbers){
	int start_ = 0;
	int end_ = inputNumbers().size()-1;	
	
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
		
			int idealItemsInLowerRange = mid+1;
			
			if(itemsInlowerRange > idealItemsInLowerRange){
				start_ = lowerRangeStart
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
	
	vector<int> inputNumbers = {1,2,3,4,5,6,7,8,9,9,10};
	cout<<"The repeated number is:"<<findRepeat(inputNumbers);
	return 0;
}
