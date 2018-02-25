#include<iostream>

using namespace std;

//1. Class for  Node
class Node{
public:
    int val;
    Node* next;
    Node(int value){
        this->val = value;
        this->next = nullptr;
    }
};
//3. function to detect loop and break the loop

void detectAndBreakLoop(Node* head){

    int len=0;
    //if list is empty or has only one node
    if(head==nullptr || head->next == nullptr){return;}

    Node* slow = head;
    Node* fast = head;

    //No need of slow pointer, as fast visits each node ahead of slow and checks all the conditions
    //checking fast->next too to avoid nullptr exception
    //Ex: 3->null: fast=3; fast->next = null; fast->next->next=>segmentation error
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){break;}
    }

    if(slow!=fast){
        cout << "No loop detected at" << endl;
        return;
    }

    cout << "Loop detected at->" << slow->val << endl;

    /**length of the loop**/
    //At this point, slow and fast are pointing the same node where loop is detected
    slow = slow->next;
    len++;

    while(slow!=fast){
        len++;
        slow = slow->next;
    }
    cout << "Length of the loop->" << len << endl;

    /** Find the beginning of the loop. Break the loop and fix the linked list **/
    //Relocate the slow pointer to the beginning of the list and leave fast as is
    Node* prev = nullptr;
    slow = head;
    while(slow->next!= fast->next){
        slow = slow->next;
        //prev = fast; -> This can be eliminated by changing while(slow to slow->next....
        fast = fast->next;
    }
    cout << "Beginning of the loop->" << slow->next->val << endl;

    //Break the loop
    fast->next = nullptr;

    return;
}

void printLinkedList(Node* head){
    if(head==nullptr)return;
    while(head!=nullptr){
        cout<<head->val<<"\t";
        head = head->next;
    }
    cout << "\n";
    return;
}

int main(){
    /**1->2->3->4
            |__5| **/
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    /** Form a loop between 3 and 5**/
    head->next->next->next->next->next = head->next->next;
    detectAndBreakLoop(head);
    printLinkedList(head);

}


/**
Reference: https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/
**/
