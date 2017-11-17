/**
When we assign a NULL to an integer
it gives warning about “Converting from NULL to non-pointer type”

nullptr is really a “null pointer” and always a pointer.
If you try assigning it to integer. It will cause an error

**/
#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
};

void Insert(Node* test){
    test->data = 100;
    test->left = nullptr;
}
int main(){
    Node node;
    // node.data = NULL; -> This will give a warning
    // node.data = nullptr; -> This will throw an error
    node.left = nullptr;
    node.right = NULL;
    node.data = 3;
    cout<< "Address of data " << &node.data << endl;
    cout<< "Address of data " << &node.left << endl;
    cout<< "Address of data " << &node.right << endl;
    Insert(&node);
    cout<< "Address of data " << node.data << endl;
}
