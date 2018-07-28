/**
    Author: Santosh Tandrothu
    Date: 07/28/2018

    Problem:



    Algo:
    1.


 **/

 /**
        Run-time Complexity:
        Space Complexity:
 **/
#include<iostream>
#include<deque>

using namespace std;

void FindMaxinWindow(int *arr, int *maxArr, int arr_size, int w_size){

    deque<int> deq;
    int i,j=0;
    int max_ele,w_track=1;
    for(i=0;i<w_size;i++){
        while(!deq.empty() && arr[i] >= arr[deq.back()]){
            deq.pop_back();
        }
        deq.push_back(i);

    }
maxArr[j++] = arr[deq.front()];
    for(;i<arr_size;i++){

        //out of the window scope
        while(!deq.empty() && deq.front() <= i - w_size){
            deq.pop_front();
        }

        //building new max
        while(!deq.empty() && arr[i] >= arr[deq.back()]){
            deq.pop_back();
        }
        deq.push_back(i);

        maxArr[j++] = arr[deq.front()];
    }
    //maxArr[j++] = arr[deq.front()];

}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int w_size = 3;
    int arr_size = sizeof(arr)/sizeof(*arr);
    int no_of_windows = arr_size - w_size + 1;
    int maxArr[no_of_windows];
    FindMaxinWindow(arr,maxArr,arr_size,w_size);
    for(int i=0;i<no_of_windows;i++){
        cout << "\t" << maxArr[i] ;
    }
    return 0;
}
