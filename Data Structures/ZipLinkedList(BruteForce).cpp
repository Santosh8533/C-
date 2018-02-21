#include <bits/stdc++.h>

using namespace std;

class LinkedListNode {
public:
    int val;
    LinkedListNode* next;

    LinkedListNode(int node_value) {
        val = node_value;
        next = NULL;
    }
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode* head, LinkedListNode* tail, int val) {
    if (!head) {
        head = new LinkedListNode(val);
        tail = head;
    } else {
        LinkedListNode* node = new LinkedListNode(val);
        tail->next = node;
        tail = tail->next;
    }

    return tail;
}


void swap(LinkedListNode* head, int x, int y){

    LinkedListNode* temp;
    temp = head;

    //Traverse the linkedlist to find the element in the 'x' position and store the address in 'a'
    while(x>1){
        temp = temp->next;
        x--;
    }
    LinkedListNode* a = temp;

    //Traverse the linkedlist to find the element in the 'y' position and store the address in 'b'
    temp = head;
    while(y>1){
        temp = temp->next;
        y--;
    }
    LinkedListNode* b = temp;

    //swap a and b values
    int tem = a->val;
    a->val = b->val;
    b->val = tem;

    return;
}


LinkedListNode* zip_given_linked_list(LinkedListNode* head) {

    //declaration
    int len=0;

    //find length of the linkedlist
    LinkedListNode* temp = head;
    while(temp!=nullptr){
        temp=temp->next;
        len++;
    }

    //Traverse the linkedlist and update the nodes in-place
    int n = len;
    for(int i=1;i<=len;i=i+2){
        int j=i;
        if(j<n || j>len)swap(head,++j,n--);
        if( j<len)swap(head,++j,len);
    }

    return head;

}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    int head_size;
    cin >> head_size;
   // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    LinkedListNode* head = NULL;
    LinkedListNode* head_tail = NULL;

    for (int head_i = 0; head_i < head_size; head_i++) {
        int head_item;
        cin >> head_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        head_tail = _insert_node_into_singlylinkedlist(head, head_tail, head_item);

        if (!head_i) {
            head = head_tail;
        }
    }


    LinkedListNode* res = zip_given_linked_list(head);

    while (res) {
        cout << res->val;

        if (res->next) {
            cout << "\t";
        }

        res = res->next;
    }

    cout << "\n";


    return 0;
}
