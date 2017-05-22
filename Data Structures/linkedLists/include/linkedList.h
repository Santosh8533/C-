#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class Node
{
public:
    Node* next;
    int data;
};

using namespace std;

class LinkedList
{
public:
    int length;
    Node* head;
    LinkedList();
    ~LinkedList();
    void addNodeAtBeginning(int data);
    void addNodeAtEnd(int data);
    void print();
};



#endif // LINKEDLIST_H
