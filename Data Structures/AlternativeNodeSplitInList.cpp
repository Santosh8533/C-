
    /**
        Author: Santosh Tandrothu
        Date: 06/16/2018
        Problem: Given a linked list, form a two separate lists by pushing every
        other element into other list
        Example: 1->2->3->4->5
        Answer:  1->3->5 and 2->4
    **/

    /***
        Time Complexity = O(n)
        Space Complexity = O(1)
    **/


#include<iostream>
#include<vector>

using namespace std;

//LinkedList Node
class Node{
public:
    int val;
    Node *next;
};

//InsertEleAtEnd
void InsertEleAtEnd(Node** head,int val){
    Node *newNode = new Node;
    newNode->val = val;
    newNode->next = nullptr;

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
    if(head){
            Node* temp = head;
            while(temp){
                cout<<temp->val<<"->\t";
                temp = temp->next;
            }
            cout<<endl;
    }
}

Node* newNode(int val){
    Node* newNode = new Node;
    newNode->val = val;
    newNode->next = nullptr;

    return newNode;
}


int listLength(Node* temp){
    int len = 0;
    if(temp){
        //Node* temp = head;
        while(temp!=nullptr){
            temp = temp->next;
            len++;
        }
    }
return len;
}


vector<Node*> AltNodeSplit(Node* head){
    if(head){
        int _count = 1;

        Node* currHead = head;
        Node* l1_head = nullptr;
        Node* l2_head = nullptr;
        Node* l1_prev = nullptr;
        Node* l2_prev = nullptr;
        Node* next = nullptr;
        while(currHead!=nullptr){
        next = currHead->next;
            if(_count%2!=0){
                if(!l1_head){
                        l1_head = currHead;
                        l1_prev = currHead;
                }
                else{
                    l1_prev->next = currHead;
                    l1_prev = currHead;
                }
            }
            else{
                if(!l2_head){
                        l2_head = currHead;
                        l2_prev = currHead;
                }
                else{
                    l2_prev->next = currHead;
                    l2_prev = currHead;
                }
            }
            currHead = next;
           _count++;
        }
        l2_prev->next = nullptr;
        l1_prev->next = nullptr;

        vector<Node*> v;
        v.push_back(l1_head);
        v.push_back(l2_head);
        return v;
    }
}
int main(){
    Node* head = nullptr;
    InsertEleAtEnd(&head,1);
    InsertEleAtEnd(&head,2);
    InsertEleAtEnd(&head,3);
    InsertEleAtEnd(&head,4);
    InsertEleAtEnd(&head,5);
    InsertEleAtEnd(&head,6);
    InsertEleAtEnd(&head,7);
    //InsertEleAtEnd(&head,8);
    PrintList(head);
    int len = listLength(head); //1.O(n)
    cout<<"Length:"<<len<<endl;
    vector<Node*> v;
    v = AltNodeSplit(head);
    cout<<"First List"<<endl;
    PrintList(v[0]);
    cout<<"Second List"<<endl;
    PrintList(v[1]);
    //PrintList(head);
}
