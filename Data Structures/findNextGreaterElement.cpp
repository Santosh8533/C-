    /**
        Author: Santosh Tandrothu
        Date: 10/06/2018
        Problem: Given an array of integers, find the next greatest element for each of the integer
        Ex: int arr[]= {5,3,2,10,6,8,1,4,12,7,9};
                for 5->10
                    3-10
                    2-10
                    10-12
                    6-8
                    8-12
                    1-4
                    4-12
                    7-9
                    12&9-x
    **/

    /***
        Time Complexity = O(n)
        Space Complexity = O(n or stack size) (Worst case when numbers are in descending order)
    **/

#include<iostream>
#include<stack>

using namespace std;

void findNextGreaterElement(int arr[],int _size){

    //1. Create a stack
    stack<int> elements;

    //2. Push the first element
    int i=0;
    elements.push(arr[i]);

    //3. Start comparing from second element with top element on stack
    for(i=1;i<_size;i++){

        //4. If it less than the top element - push back
        if(arr[i]<elements.top()){
            elements.push(arr[i]);
        }

        //5. If it greater than the top element - print current element as top's greater element
        if(arr[i] > elements.top()){

            while(arr[i] > elements.top()){
                cout<<"NGE for "<<elements.top()<<"is:"<<arr[i]<<endl;
                elements.pop();
                if(elements.empty()){break;}
            }
            elements.push(arr[i]);

        }
    }

    while(!elements.empty()){
        cout<<"NGE for "<<elements.top()<<"is:___"<<endl;
        elements.pop();
    }



   // 6. Repeat step 5 for all the elements on the stack until step 5 fails
    //7. When step 5 fails, push the current element and go to the next element in the array


}


int main(){

    int arr[] = {5,3,2,10,6,8,1,4,12,7,9};
    int _size = sizeof(arr)/sizeof(arr[0]);
    findNextGreaterElement(arr,_size);

}

/***
Next Steps:
1. Refer method 2 and 3 in https://www.geeksforgeeks.org/next-greater-element/
***/
