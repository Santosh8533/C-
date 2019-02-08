#include<iostream>
#include<vector>

using namespace std;
//DP approach
//Time: O(n^2)
//Space: O(n^2)
int maxSubArrayN2(const vector<int> &A) {

    if(A.empty()) return 0;
    int n = A.size();
    int sum[n][n];
    int max = A[0];

    for(int col=0;col<n;col++){
        sum[0][col] = A[col];
        if(sum[0][col] > max){max = sum[0][col];}
    }

    for(int row=1;row<n;row++){
        for(int col=row;col<n;col++){
            sum[row][col] = sum[row-1][col-1] + A[col];
            if(sum[row][col] > max){max = sum[row][col];}
        }
    }

    return max;
}
/**Kadane's algorithm: Add x numbers, if sum is negative - its not contributing to
the maximum sum, reset the current sum to zero. If sum is positve,contributing to
maximum, keep going on and track the maximum sum.
**/
//[-2,1,-3,4,-1,2,1,-5,4]
int maxSubArrayN(const vector<int> &nums){
    //initializing maximum number with first number will be fine
    //if first number is largest of all than sum of sub array elements - then no problem
    //if first number is smallest of all, then eventually it gets replaced in for loop
    int maximum = nums[0];
    int currMax = 0;

    for(int i=0;i<nums.size();i++){
        currMax = currMax+nums[i]; //3-5-6-1-5
        maximum = max(currMax,maximum); //4-5-6
        if(currMax<0){currMax = 0;}
    }

    return maximum;
}

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<"Overlapping sub problems approach: Run: O(n^2) - Space:O(n^2)"<<endl;
    cout<<"Max sum in contiguous sub-array:"<<maxSubArrayN(nums)<<endl<<endl;
    cout<<"Kadane's algorithm: Run: O(n) - Space:O(1)"<<endl;
    cout<<"Max sum in contiguous sub-array:"<<maxSubArrayN2(nums)<<endl;
}
