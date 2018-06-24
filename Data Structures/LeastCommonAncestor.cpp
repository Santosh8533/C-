    /**
        Author: Santosh Tandrothu
        Date: 06/24/2018
        Problem: Given a BST, find least common ancestor of given any two nodes
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
    Node* LCA(Node*,Node*);
    bool findPathToNodeFromRoot(Node*,vector<int>&,bool,int);

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

Node* BinaryTree::LCA(Node* node1,Node* node2){
    Node* LCANode = createNode(0);
    bool trig = false;
    bool trigger = false;
    //vectors to store the path from root to node1 and node2
    vector<int> v1,v2;
    //find the path for n1 and n2
    bool vb1 = findPathToNodeFromRoot(root,v1,trigger,node1->value);
    bool vb2 = findPathToNodeFromRoot(root,v2, trigger,node2->value);

    cout<<"vb1:"<<vb1<<endl;
    cout<<"vb2:"<<vb2<<endl;

    cout<<"vector1:"<<endl;
    vector<int>::iterator it1,it2;
    for(it1=v1.begin();it1!=v1.end();it1++){
        cout<<*it1<<"\t";
    }
    cout<<endl;

    cout<<"vector2:"<<endl;
    for(it2=v2.begin();it2!=v2.end();it2++){
        cout<<*it2<<"\t";
    }
    cout<<endl;

    if(vb1 && vb2){
        //vector<int>::iterator it1,it2;
        it1 = v1.begin();
        it2 = v2.begin();

        while(it1!=v1.end() && it2!=v2.end()){
            if(*it1 == *it2){
                LCANode->value = *it1;
                trig = true;
                it1++;
                it2++;

            }
            else if(trig){
                return LCANode;
            }
            else return nullptr;
        }
    }

    //compare v1 and v2
    return LCANode;
}

bool BinaryTree::findPathToNodeFromRoot(Node* currRoot,vector<int>& v,bool trigger, int target){


    if(currRoot == nullptr){return false;}
    //push the node value into the vector
    v.push_back(currRoot->value);
    //This condition acts a trigger and if target is detected - it returns to
    //calling function without traversing the tree anymore
    if(currRoot->value == target){return true;}

    trigger = findPathToNodeFromRoot(currRoot->left,v,trigger,target);
    if(trigger){return true;} //this condition takes back to calling function without
    //traversing further

    trigger = findPathToNodeFromRoot(currRoot->right,v,trigger,target);
    if(trigger){return true;} //this condition takes back to calling function without
    //traversing further

    v.pop_back();
    return trigger;

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
   // cout << "Is this tree a BST?" << bt.isBST()<<endl;
   Node* node1 = bt.createNode(2);
   Node* node2 = bt.createNode(6);
   Node* LCANode = bt.LCA(node1,node2);
   cout<<"LCANode"<<LCANode->value<<endl;

    return 0;
}
