#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int kthMostOccuringElement(const vector<int>& nums, int k){
    unordered_map<int,int> eleMap;
    int i=0,j=0;
    for(i=0,j=nums.size()-1;i<j;i++,j--){
        auto sit = eleMap.find(nums[i]);
        if(sit!=eleMap.end() && sit->second > k){
            eleMap.erase(sit);
        }
        else eleMap[nums[i]]++;

        auto sjt = eleMap.find(nums[j]);
        if(sjt!=eleMap.end() && sjt->second > k){
            eleMap.erase(sjt);
        }
        else eleMap[nums[j]]++;
    }
    if(i==j){
        auto sjt = eleMap.find(nums[j]);
        if(sjt!=eleMap.end() && sjt->second > k){
            eleMap.erase(sjt);
        }
        else eleMap[nums[j]]++;
    }

    for(auto it1=eleMap.begin();it1!=eleMap.end();it1++){
        cout<<it1->first<<"\t"<<it1->second<<endl;
    }

    for(auto it=eleMap.begin();it!=eleMap.end();it++){
        if (it->second == k) return it->first;
    }
    return 0;
}

int main(){
    vector<int> v={2,1,2,1,2,4,4,1,1};
    cout<<kthMostOccuringElement(v,3);
}
