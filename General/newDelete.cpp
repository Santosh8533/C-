/**new and delete operators in C++**/

#include<iostream>

using namespace std;

class Test{
public:
    Test(){
        cout << "Class created" << endl;
    }
    ~Test(){
        cout << "Class destroyed" << endl;
    }
};
int main(){
    int *i = new int;
    if(i!=nullptr){

        cout << "Memory assigned" << endl;
        cout << "Assigned address to i:->" << i << endl;
        cout << "Value of i:->" << *i << endl; /**Garbage value*/

        *i = 2;
        cout << "Assigned address to i:->" << i << endl;
        cout << "Value of i:->" << *i << endl;

        delete i;

        /**Deleting means freeing the memory. So that processor
        can use that memory for other processes**/
        i = nullptr;
        /**after freeing memory, it should be pointed to NULL
        to avoid invalid pointers**/


        cout << "Assigned address to i:->" << i << endl;
       // cout << "Value of i:->" << *i << endl;
        }

       /**************Class*********************/

       Test *test = new Test;
       /**Output: Class created**/

       delete test;
       /**Output: Class destroyed**/

       /**************Block of memory*********************/
       int *mem = new int[10]; /**All these elements are allocated contiguously**/
       for(int i=0;i<10;i++){
            cout<< &mem[i] << endl;
       }
       /**Allocates 10 integers space in heap and returns the address of the first variable**/
       mem[0] = 1;
       mem[0] = 2; /** To access the elements**/
       delete [] mem; /**frees the block of the memory**/
    return 0;
}
