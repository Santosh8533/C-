/**
    Author: Santosh Tandrothu
    Date: 2/27/2019
**/

/**
    Time complexity = O(n1) + O(n2)
    Space complexity = O(n1) + O(n2) (considering worst-case of not having any intersection)
**/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
private:
	unordered_map<int, int> hashmap;
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(auto it:nums1) {
        	if(hashmap.count(it) > 0)
        		hashmap[it]++;
        	else
        		hashmap[it] = 1;
        }
        for(auto it:nums2) {
        	if(hashmap.count(it) > 0) {
        		res.push_back(it);
        		hashmap[it]--;
        		if(hashmap[it] == 0)
        			hashmap.erase(it);
        	}
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<int> nums1={4,9,5};
    vector<int> nums2={9,4,9,6,4};
    vector<int> res= s.intersect(nums1,nums2);
    for(int i:res){
        cout<<i<<endl;
    }
}
