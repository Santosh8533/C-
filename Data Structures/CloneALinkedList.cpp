    /**
        Author: Santosh Tandrothu
        Date: 06/14/2018
        Problem: Given a Double Link List with one pointer of each node pointing to the next node just like in a single link list. 
        The second pointer however CAN point to any node in the list and not just the previous node.
        Ref: https://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
    **/

    /***
        Time Complexity = O(2n) ~= O(n)
        Space Complexity = O(n) 
    **/


#include<iostream>
#include<unordered_map>

using namespace std;

//LinkedList Node
class Node{
public:
    int val;
    Node *next;
    Node *random;
};

//InsertEleAtEnd
void InsertEleAtEnd(Node** head,int val){
    Node *newNode = new Node;
    newNode->val = val;
    newNode->next = nullptr;
    newNode->random = nullptr;

    if(!*head){
        *head = newNode;
    }

    else{
        Node* temp = *head;
        while(temp->next!=nullptr){temp=temp->next;}
        temp->next = newNode;
    }
}

void PrintList(Node* head){
    if(head!=nullptr){
            Node* temp = head;
            while(temp){
                cout<<temp->val<<"->\t"<<temp->random->val<<endl;
                temp = temp->next;
            }
            //cout<<endl;
    }
}


int listLength(Node* head){
    int len = 0;
    Node* temp = head;
    if(temp){
        //Node* temp = head;
        while(temp!=nullptr){
            temp = temp->next;
            len++;
        }
    }
return len;
}

Node* newNode(int val){
    Node* newNode = new Node;
    newNode->val = val;
    newNode->next = nullptr;
    newNode->random = nullptr;

    return newNode;
}


Node* cloneList(Node* head){
    if(head){
            //cout<<"entered"<<endl;
        Node* origNode = head;
        Node* cloneNode =  nullptr;

        unordered_map<Node*,Node*> linkMap;

        while(origNode!=nullptr){
            cloneNode = newNode(origNode->val);
            cout<<origNode->val<<endl;
            linkMap[origNode] = cloneNode;
            origNode = origNode->next;
        }

        origNode = head;

        while(origNode!=nullptr){
            cloneNode = linkMap[origNode];
            cloneNode->next = linkMap[origNode->next];
            cloneNode->random = linkMap[origNode->random];
            origNode = origNode->next;
        }
        return linkMap[head];
    }
    return nullptr;
}

int main(){

    Node* head = nullptr;
    InsertEleAtEnd(&head,1);
    InsertEleAtEnd(&head,2);
    InsertEleAtEnd(&head,3);
    InsertEleAtEnd(&head,4);
    InsertEleAtEnd(&head,5);
    //InsertEleAtEnd(&head,6);
    //InsertEleAtEnd(&head,7);
    //InsertEleAtEnd(&head,8);

    // Setting up random references.
    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head;
    head->next->next->next->next->random = head->next;

    PrintList(head);
    int len = listLength(head); //1.O(n)
    cout<<"Length:"<<len<<endl;

    Node *cloneHead = cloneList(head);
    PrintList(cloneHead);
}
