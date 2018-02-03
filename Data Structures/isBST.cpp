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

/** Is it a BST?**/
/*
bool BinaryTree::isBST(){
    if(root==nullptr){return false;}
    int leftMax =0, rightMax = 0;
    cout << "Left subtree" << endl;
    isBST(root->left, &leftMax);
    cout << "Right subtree" << endl;
    isBST(root->right, &rightMax);
    if(leftMax < root->value && rightMax > root->value){return true;}
    return false;
}

void BinaryTree::isBST(Node* currentRoot, int* Max){
    if(currentRoot == nullptr){return;}
    if(*Max < currentRoot->value){
            *Max = currentRoot->value;
            cout << *Max << "\t";
    }
    isBST(currentRoot->left, Max);
    isBST(currentRoot->right, Max);
    return;
}*/

bool BinaryTree::isBST(){
    return isBST(root,INT_MIN,INT_MAX );
}

bool BinaryTree::isBST(Node* currentRoot, int MIN, int MAX){

    if(currentRoot==nullptr){return true;}
    if(currentRoot->value > MIN && currentRoot->value < MAX){return true;}
    else return false;
    return isBST(currentRoot->left, MIN, currentRoot->value-1) &&
           isBST(currentRoot->right, currentRoot->value+1, MAX);
}

int main(){

    BinaryTree bt;
    bt.insertNode(50);
    bt.insertNode(40);
    bt.insertNode(100);
    bt.insertNode(2);
    bt.insertNode(45);
    bt.insertNode(120);
    bt.insertNode(80);
    bt.displayTree();
    cout << "Is this tree a BST?" << bt.isBST()<<endl;

    return 0;
}
