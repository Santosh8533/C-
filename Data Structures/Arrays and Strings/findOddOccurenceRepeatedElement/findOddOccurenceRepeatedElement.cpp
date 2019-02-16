#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int findOddOccurenceRepeatedElement(const vector<int>& nums){
    //traverse - save the frequency in map
    unordered_map<int,int> eleCounter;
    for(int i=0;i<nums.size();i++){
        if(eleCounter.find(nums[i])==eleCounter.end()){
            eleCounter[nums[i]]++;
        }
        else{
            eleCounter.erase(nums[i]);
        }
    }

    if(!eleCounter.empty()) return eleCounter.begin()->first;
    return  0;

    /*for(auto it1=eleCounter.begin();it1!=eleCounter.end();it1++){
        cout<<it1->first<<"\t"<<it1->second<<endl;
    }

    int maxOddRep=0;
    int maxOddRepNumber=0;
    for(auto it=eleCounter.begin();it!=eleCounter.end();it++){
        if((it->second > maxOddRep) && (it->second%2!=0)){
            maxOddRep = it->second;
            return it->first;
        }
    }
    return maxOddRepNumber;*/
}

int main(){
    vector<int> v={2,1,2,1,2,4,4};
    cout<<findOddOccurenceRepeatedElement(v);
}
