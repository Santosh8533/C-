#include<vector>
#include<iostream>

using namespace std;

void MergeSortUtil(vector<int>& nums,int left, int right){
    if(left>=right) return;
    int mid = (left+right)/2;
    if(mid!=0)MergeSortUtil(nums,left,mid-1);
    if(mid!=0)MergeSortUtil(nums,mid,right);
    while(left<=mid){
        if(nums[left]>nums[right]){
            swap(nums[left],nums[right]);
            left++;
        }
        else{
            swap(nums[right],nums[left]);
            mid++;
        }
    }
}

void MergeSort(vector<int>& nums){
    int left, right;
    left = 0;
    right = nums.size()-1;
    MergeSortUtil(nums,left,right);
}

int main(){
    vector<int> nums = {12, 11, 13, 5, 6, 7};
    //vector<int> nums = {1,2};
    MergeSort(nums);
    for(int i:nums){
        cout<<i<<"\t";
    }
}
