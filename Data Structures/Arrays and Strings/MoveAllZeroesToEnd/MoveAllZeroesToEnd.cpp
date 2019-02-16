
#include<iostream>
#include<vector>

using namespace std;

void moveAllZereosToEnd(vector<int>& nums){
    //traverse - save the frequency in map
    int count_=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){continue;}
        nums[count_] = nums[i];
        if(count_<i)nums[i] = 0;
        count_++;
    }

}

int main(){
    vector<int> v={2,0,1,0,2,3,4};
    moveAllZereosToEnd(v);
    for(int i:v){cout<<i<<"\t";}
}
