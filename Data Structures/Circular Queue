/******************************************************************************

                       

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
        front = size-1;
        rear = size-1;
    }
    bool enquee(int);
    int dequee();
    bool isQueueEmpty();
    void printQueue();
};

bool Cqueue::isQueueEmpty(){
    //This covers front and rear when - 1 as well as other positons (1,2,3.....)
    if(front == rear){
        cout << "Queue is empty" << endl;
        return true;
    }
    return false;
}

bool Cqueue::enquee(int ele){
    //1.Check if Queue is full)
    
    int temp = (rear + 1) % size;  //rear should not be updated when queue is full
    if(temp == front){
        cout << "Queue is full" << endl;
        return false;
    }
    else{
        rear = temp;// rare should be updated only on successful insertion
        arr[rear] = ele;
        //rear++;
        
    }
    //2.Increment rear and insert the element in the rear positon
}

int Cqueue::dequee(){
    if(isQueueEmpty()){
    return -1;
    }
    front = (front+1)%size;
    return arr[front];
    
}

void Cqueue::printQueue(){
    //Startpoint: ear element
    //endpoint: front element
    int temp = front;
    while(rear!=front)
    {
        front = (front + 1) % size; 
        cout << "Element" << arr[front] << endl;
    }
    front = temp;
    cout << "\n_________________ \n";
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
    q.printQueue();
    q.dequee();
    q.dequee();
    q.printQueue();
    q.dequee();
    q.dequee();
    q.dequee();
    q.printQueue();
    return 0;
}



