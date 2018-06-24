    /**
        Author: Santosh Tandrothu
        Date: 06/23/2018
        Problem: Given a BST, perform inorder traversal using iterative approach
    **/

    /***
        Time Complexity = O(n)
        Space Complexity = O(h) (Height of the tree)
    **/

#include<iostream>
#include<limits>
#include<vector>
#include<stack>

using namespace std;

class Node{
    public:
    int value;
    Node *left;
    Node *right;
};

class BinaryTree{

    Node *root;

    public:
    BinaryTree();
    Node* createNode(int);
    void insertNode(int);
    void insertNode(Node*,Node*);
    void displayTree();
    void inOrderTraversal(Node*);
    bool isBST();
    bool isBST(Node*, int,int);
    void inOrderTraversalIterative();

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

void BinaryTree::inOrderTraversalIterative(){
    stack<Node*> s;
    Node* currRoot = root;
    //s.push(root);
    bool stop = false;
    //if stack is not empty
    while(!stop){
        //if currRoot is not nullptr
        if(currRoot!=nullptr){
            s.push(currRoot);
            currRoot = currRoot->left;
        }
        //if nullptr that means either it is a root or node without left or right child
        //Pop a node from stack and make curr point to right of popped node
        else if(s.empty())stop=true;
        else{
            currRoot = s.top();
            cout<<currRoot->value<<endl;
            currRoot = currRoot->right;
            s.pop();
        }
    }
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
    //bt.displayTree();
    cout<<"Inorder iterative: \n";
    bt.inOrderTraversalIterative();
    return 0;
}
