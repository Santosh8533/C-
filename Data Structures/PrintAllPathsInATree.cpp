    /**
        Author: Santosh Tandrothu
        Date: 06/21/2018
        Problem: Given a BST, print all the paths from root to leaf nodes
    **/

    /***
        Time Complexity = O(n)
        Space Complexity = O(h) (Height of the tree)
    **/

#include<iostream>
#include<limits>
#include<vector>

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
    void PrintAllPathsInATree();
    void PrintAllPathsUtil(Node*, vector<int>&);
    void printPaths(vector<int>);

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

//print all paths in a tree
void BinaryTree::PrintAllPathsInATree(){
    vector<int> v;
    PrintAllPathsUtil(root,v);
}

void BinaryTree::PrintAllPathsUtil(Node* currRoot,vector<int> &v){
    //if root is null - print the paths
    if(currRoot==nullptr){
            printPaths(v);
            return;
    }
    
    //push the root value to the paths
    v.push_back(currRoot->value);
    
    //if it is a leaf node - print the paths - pop the leaf node
    if(currRoot->left == nullptr && currRoot->right==nullptr){
        printPaths(v);
        v.pop_back();
        return;
    }

    //traverse left
    PrintAllPathsUtil(currRoot->left,v);
    
    //traverse right
    PrintAllPathsUtil(currRoot->right,v);
  
    //Once the children are visited, pop itself(root) from paths
    v.pop_back();
}

//print paths
void BinaryTree::printPaths(vector<int> v){
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<"\t";
    }
    cout<<"\n";
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
    cout<<"Printing All Paths in A Tree \n";
    bt.PrintAllPathsInATree();
    return 0;
}
