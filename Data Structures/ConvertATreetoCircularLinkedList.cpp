        /**
            Author: Santosh Tandrothu
            Date: 07/10/2018
            Problem: Convert Tree to Circular Doubly Linked List

            Algorithm:

        **/

        /***
            Time Complexity = O(n) (Traversing all the nodes in a tree)
            Space Complexity = O(h) (height of the tree)
        **/

#include<iostream>
#include<limits>

using namespace std;

class Node{
    public:
    int value;
    Node *left;
    Node *right;
};

class BinaryTree{

    Node *root,*head,*tail;

    public:
    BinaryTree();
    Node* createNode(int);
    void insertNode(int);
    void insertNode(Node*,Node*);
    void displayTree();
    void inOrderTraversal(Node*);
    bool isBST();
    bool isBST(Node*, int,int);
    Node* BSTtoLL();
    Node* BSTtoLL(Node*, Node**);
    void displayList();

};

/** Constructor**/
BinaryTree::BinaryTree(){
    root = nullptr;
}

/** Create a node**/
Node* BinaryTree::createNode(int val){
    //Assign memory

    Node *node = new Node;

    //Initialize
    node->value = val;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}

/** Insert a node**/
void BinaryTree::insertNode(int val){

    Node* node = createNode(val);
    //If tree is empty
    if(root == nullptr){
        root = node;
        //cout<<"root value" <<root->value<<endl;
        return;
    }

    insertNode(root,node);

    return;
}

/** Insert a node - function overwriting**/
void BinaryTree::insertNode(Node* curRoot, Node *node){

    if(curRoot == nullptr){
        return;
    }

    if(node->value < curRoot->value){
        insertNode(curRoot->left, node);
        if(curRoot->left == nullptr){
                curRoot->left = node;
                //cout << "Inserted at left->" << curRoot->left->value <<endl;
        }
    }

    else if(node->value > curRoot->value){
        insertNode(curRoot->right, node);
        if(curRoot->right == nullptr){
                curRoot->right = node;
               // cout << "Inserted at right->" << curRoot->right->value <<endl;
        }
    }

    return;
}

/** Display Tree - inorder traversal**/
void BinaryTree::displayTree(){
    inOrderTraversal(root);
    return;

}

/** Inorder traversal**/
void BinaryTree::inOrderTraversal(Node* currentRoot){

    if(currentRoot==nullptr)return;

    inOrderTraversal(currentRoot->left);
    cout<<currentRoot->value<<"\t"<<endl;
    inOrderTraversal(currentRoot->right);
}


bool BinaryTree::isBST(){
    return isBST(root,INT_MIN,INT_MAX );
}

bool BinaryTree::isBST(Node* currentRoot, int MIN, int MAX){

//IF it reaches end of the tree, that means the nodes along this subtree met the
//criteria, so true can be returned - if doesn't 'else' loop takes care of it
    if(currentRoot==nullptr){return true;}
    if(currentRoot->value > MIN && currentRoot->value < MAX){
            return isBST(currentRoot->left, MIN, currentRoot->value)&&
                   isBST(currentRoot->right, currentRoot->value, MAX);
    }
    else return false;
}

/** Convert BST to LL Utility function**/

Node* BinaryTree::BSTtoLL(Node* curr_root, Node** prev){

    if(curr_root == nullptr){return nullptr;}
    //Traverse left
    BSTtoLL(curr_root->left,prev);
    //if it is leftmost/leaf node,save it as head
    if(*prev == nullptr){head = curr_root;}
    //if it is left node(not leaf) or root, establish prev and next connections
    else{
        //prev
        curr_root->left = *prev; //1<-2
        //next
        (*prev)->right = curr_root; //1->2
    }
    //update prev to curr_root as the current visited node becomes previous node to
    //next node
    *prev = curr_root;
    //Traverse right
    BSTtoLL(curr_root->right,prev);
    //if(tail==nullptr){tail = curr_root;}

    return head;

}

/** Convert BST to LL**/
Node* BinaryTree::BSTtoLL() {
    if(root == nullptr) return nullptr;
    Node* prev = nullptr;
    Node* head = BSTtoLL(root,&prev);
    return head;
}

/**Display LL**/
void BinaryTree::displayList(){
    if(head == nullptr){return;}
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->value<<"\t";
        temp = temp->right;
    }
    cout<<endl;

    /*if(tail == nullptr){return;}
    temp = tail;
    while(temp!=nullptr){
        cout<<temp->value<<"\t";
        temp = temp->left;
    }
    cout<<endl;*/
}

int main(){

    BinaryTree bt;
    bt.insertNode(4);
    bt.insertNode(2);
    bt.insertNode(6);
    bt.insertNode(2);
    bt.insertNode(1);
    bt.insertNode(3);
    bt.insertNode(5);
    bt.insertNode(7);
    bt.displayTree();
    Node* list_head= bt.BSTtoLL();
    bt.displayList();
    return 0;
}
