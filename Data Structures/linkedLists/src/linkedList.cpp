#include "linkedList.h"
#include<iostream>

using namespace std;

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}

LinkedList::~LinkedList(){
    std::cout << "LIST DELETED";
}

void LinkedList::addNodeAtBeginning(int data){
    Node* node = new Node();
    node->data = data;
    node->next = this->head; //this refers to the object of the class LinkedList
    this->head = node; //Tried to replace this with the object name list but could not do it because list name is in scope only in main.When it is out of scope, it is referred with it's address.
    this->length++;
}

void LinkedList::addNodeAtEnd(int data){
    Node* node = new Node();
    Node* temp;
    node->data = data;
    temp = this->head; //NULL
    if(temp == NULL){this->head = node;} //HEAD = 100
    else{
        while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = node;
    }
    this->length++;
}
void LinkedList::print(){
    Node* head = this->head;
    int i = 1;
    while(head){
        std::cout << head->data << "-->";
        head = head->next;
        i++;
    }
    cout<<endl;
}
