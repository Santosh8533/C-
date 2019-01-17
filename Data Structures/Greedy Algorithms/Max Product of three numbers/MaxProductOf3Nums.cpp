#include<iostream>
#include<vector>
#include<stdexcept>

using namespace std;

int maxProductOf3Nums(const vector<int>& nums){

    if(nums.size()==0){
        throw invalid_argument("No numbers");
    }

    if(nums.size()<3){
        throw invalid_argument("There shall be atleast 3 numbers to return the product");
    }

    int maxEle = 1;
    int secMaxEle = 1;
    int thirMaxEle = 1;

    int minEle = 1;
    int secMinEle = 1;
    int thirMinEle = 1;

    for(int i=0;i<nums.size();i++){
        int currEle = nums.at(i);
        if(maxEle < currEle){
            thirMaxEle = secMaxEle;
            secMaxEle = maxEle;
            maxEle = currEle;
        }
        else if(secMaxEle < currEle){
            thirMaxEle = secMaxEle;
            secMaxEle = currEle;
        }
        else if(thirMaxEle < currEle){
            thirMaxEle = currEle;
        }

        //negative mins
        if(minEle > currEle){
            thirMinEle = secMinEle;
            secMinEle = minEle;
            minEle = currEle;
        }

        else if(secMinEle > currEle){
            thirMinEle = secMinEle;
            secMinEle = currEle;
        }

        else if(thirMinEle > currEle){
            thirMinEle = currEle;
        }
    }

    int positiveProduct = maxEle * secMaxEle * thirMaxEle;
    int mixProduct = maxEle * minEle * secMinEle;

    return max(positiveProduct,mixProduct);
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    cout<<"Max product:"<<maxProductOf3Nums(nums)<<endl;

    vector<int> nums1 = {-10, 1, 3, 2, -10};
    cout<<"Max product:"<<maxProductOf3Nums(nums1);
}
