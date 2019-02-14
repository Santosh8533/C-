#include<iostream>
#include<vector>

using namespace std;

int removeElement(vector<int> &A, int B) {
    int count_=0;
    for(int i=0;i<A.size();i++){
        if(A[i]==B){
            continue;
        }
        A[count_]=A[i];
        count_++;
    }
    return count_;
}


int main(){
    vector<int> v ={2,1,4,1,1};
    int res = removeElement(v,1);
    for(int i=0;i<res;i++){
        cout<<v[i]<<endl;
    }

}
