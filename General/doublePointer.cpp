#include<iostream>

using namespace std;

void update(int **i){
    //int k = 2; // this will be stored in the stack
    int *k = new int; // Storing in the heap.
    *k = 2;
    //Imagine this: when the argument is passed to this function -> i=&head (head's address gets copied as a i's value)
    cout << "i's value (should be same as 'Address of head itself'):->" << i <<endl;
    //Now *i = *(&head) => which points to the value present in the head's address
    cout << "The value to which i is pointing should be same as (Value of head):->" << *i << endl;
    //Now **i = *(*(&head)) => which points to the j value
    cout << "Value of j using pointer variable i:->" << **i << endl;
    //Modifying head value using i
    //We know i has the address of head. So if we change the *i value, it impacts the head value automatically
    cout << "Address of k:->" << k << endl;
    *i = k;
} // At the end of the function, K value will be removed from the stack. the head value contains garbage at the end of this function execution.


int main(){
    int j = 8;
    int *head = &j;
    cout << "Address of j:->" << &j << endl;
    //What happens at the above line
    //1. The head variable will be assigned a memory address
    cout << "Address of head itself:->" << &head << endl;
    //2. The i's address gets stored in the head as it's value
    cout << "Value of head:->" << head << endl;
    // Let's print the value the head is pointing to
    cout << "Value to which head is pointing to:->" << *head << endl;

    //Goal: To modify the value in the head. In other words point the head to some other variable
    update(&head);
    //After modification
    cout << "Head value" << head << endl;
    cout << "Head is pointing to the value" << *head << endl;
    delete head;
    //cout << "Head value" << head << endl;
    //cout << "Head is pointing to the value" << *head << endl;
    return 0;
}
