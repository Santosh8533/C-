    /**
        Author: Santosh Tandrothu
        Date: 06/13/2018
        Problem: Given a linked list, reverse the 'n' elements in a group of K taking the
                 following condition into consideration: if(k/2!=0) which meaning if
                 elements can't be divided into equal groups then the groups shall be
                 divided into floor(n/k) groups and (n%k) group. Then reverse each group and
                 combine the groups in a sequence.
        Example: 1->2->3->4->5 || n=5 || k=2 => Groups are (floor(5/2) = 2 groups and 5%2= 1)
        Answer:  2->1->4->3->5
    **/

    /***
        Time Complexity = O(2n) ~= O(n)
        Space Complexity = O(k) (considering the internal stack space to store the elements in the recursive function)
    **/


#include<iostream>

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

Node* reverseK(Node* head,int len, int k){
    if(head){
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        int _count = 0;

        while(curr && _count<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            _count++;
        }

        if(next){
            len = len - k;
            if(k>len){k=len;}
            head->next = reverseK(next,len,k);
        }
        return prev;
    }
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


int main(){
    int k=3;
    Node* head = nullptr;
    InsertEleAtEnd(&head,1);
    InsertEleAtEnd(&head,2);
    InsertEleAtEnd(&head,3);
    InsertEleAtEnd(&head,4);
    InsertEleAtEnd(&head,5);
    InsertEleAtEnd(&head,6);
    InsertEleAtEnd(&head,7);
    InsertEleAtEnd(&head,8);
    PrintList(head);
    int len = listLength(head); //1.O(n)
    cout<<"Length:"<<len<<endl;
    head = reverseK(head,len,k); //2. O(n)
    PrintList(head);
}
