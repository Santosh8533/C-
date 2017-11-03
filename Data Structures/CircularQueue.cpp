/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Cqueue{
    public:
    int front, rear;
    int size;
    int arr[5];
    //Only static variables should be initialized inside the class else in the constructor::good practice
    Cqueue(){
        size = 5;
        front = -1;
        rear = -1;
    }
    bool enquee(int);
    int dequee();
    bool isQueueEmpty();
    void printQueue();
    bool isQueueFull();
};

bool Cqueue::isQueueEmpty(){
    //This covers front and rear when - 1 as well as other positons (1,2,3.....)
    if(front == rear){
        cout << "Queue is empty" << endl;
        return true;
    }
    return false;
}

bool Cqueue::isQueueFull(){
    
    if(front == -1 && rear == size-1){front = 0;}
    if(front == ((rear+1)%size)){
        cout << "Queue is full" << endl;
        return true;
    }
    return false;
}

bool Cqueue::enquee(int ele){
    if(isQueueFull()) return false;
    //rear initial value = -1
    rear = (rear+1)%size;
    arr[rear] = ele; 
    cout << "Element inserted" << arr[rear] << endl;
    return true;
}

int Cqueue::dequee(){
    if(isQueueEmpty())return -1;
    front = (front+1)% size;
    cout << "dequeed element" << arr[front] << endl;
    return arr[front];
}

void Cqueue::printQueue(){
    //Startpoint: rear element
    //endpoint: front element
    
    int temp = front;
    while(!isQueueEmpty()){
        cout << "temp->" << temp << endl; 
        cout << "element:" << arr[temp] << endl;
        temp = (temp+1)%size;
    }
    cout << arr[temp] << endl;
    cout << "______________________________" << endl;
}

int main()
{
    cout<<"Hello World \n";
    Cqueue q;
    q.isQueueEmpty();
    q.enquee(10);
    q.enquee(20);
    q.enquee(30);
    q.enquee(40);
    q.enquee(50);
    q.enquee(60);
    //q.printQueue();
    q.dequee();
    q.dequee();
   // q.printQueue();
    q.dequee();
    q.dequee();
    q.dequee();
    q.dequee();
    
    //q.printQueue();
    return 0;
}
