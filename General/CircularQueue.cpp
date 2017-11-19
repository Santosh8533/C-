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
        front = 0;
        rear = 0;
    }
    bool isQueueEmpty();
    bool isQueueFull();
    bool enquee(int);
    int dequee();
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

/**Difference between front and rear is 1 when queue is fall. rear is always leading**/
bool Cqueue::isQueueFull(){
    if(front = (rear+1)%size))return true;
    return false;
}

bool Cqueue::enquee(int ele){
    if(isQueueFull()){return false;}
    arr[rear] = ele;
    rear = (rear+1)%size;
}

int Cqueue::dequee(){
    if(isQueueEmpty()){return -1;}
    int temp = front;
    front = (front+1)%size;
    return arr[temp];

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
