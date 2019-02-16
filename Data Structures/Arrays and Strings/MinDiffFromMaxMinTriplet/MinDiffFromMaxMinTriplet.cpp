#include<iostream>
#include<vector>
#include<climits> //what is INT_MAX
#include<algorithm>

using namespace std;
int maxNum(int first,int second,int third){
    if(first>second){return first>third?first:third;}
    else return second>third?second:third;
}

int minNum(int first,int second,int third){
    if(first<second){return first<third?first:third;}
    else return second<third?second:third;
}

int MinDiffFromMaxMinTriplet(vector<int> v1, vector<int> v2, vector<int> v3){

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end());

    int i=0,j=0,k=0;
    int minDiff = INT_MAX;
    while(i<v1.size() && j<v2.size() && k<v3.size()){
        int first = v1[i];
        int second = v2[j];
        int third = v3[k];
        cout<<first<<"\t"<<second<<"\t"<<third<<"-->";
        int max_ = maxNum(first,second,third);
        int min_ = minNum(first,second,third);
        int currDiff = max_-min_;
        cout<<max_<<"\t"<<min_<<"\t"<<currDiff<<endl;
        minDiff = min(minDiff,currDiff);

        if(v1[i] == min_){
                if(i==v1.size()-1 && v1[i]<=v2[j] && v1[i]<=v3[k]){break;}
                else i++;
        }
        else if(v2[j]==min_){
                if(j==v2.size()-1 && v2[j]<=v1[i] && v2[j]<=v3[k]){break;}
                else j++;
        }
        else if(v3[k]==min_){
                if(k==v3.size()-1 && v3[k]<=v1[i] && v3[k]<=v2[j]){break;}
                k++;
        }
    }
    return minDiff;
}

int main(){
    vector<int> arr1= {5, 2, 8};
    vector<int> arr2= {10, 7, 12};
    vector<int> arr3 = {9, 14, 6};

    cout<<MinDiffFromMaxMinTriplet(arr1, arr2, arr3);
}
