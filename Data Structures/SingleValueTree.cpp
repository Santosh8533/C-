/**
    Author: Santosh Tandrothu
    Date: 07/11/2018

    Problem: Given a binary tree, find the number of single value trees.

            5
          /   \
        5      5
      /  \      \
     5    5      5 
     
              Single Value Trees: 5-5(right subtree of 5), 5-5-5(left), entire tree => 3
                                  all leaf nodes = 3
                                  Total= 6 subtrees
 **/

 /**
        Run-time Complexity: O(n^2)
        Space Complexity: O(1) or O(h) h=height of the tree and considering OS stack
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

// Utility function to create a new node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->value = val;
    temp->left = temp->right = nullptr;
    return (temp);
}

bool findSingleValueTreesUtil(Node* currRoot,int& _count){

    if(currRoot == nullptr) {return true;}

    bool left = findSingleValueTreesUtil(currRoot->left,_count);
    bool right = findSingleValueTreesUtil(currRoot->right,_count);

    //if one of the nodes in the tree is not uni value, the it's not single value tree
    if(left == false || right == false){
        return false;
    }

    //if left is not null but value not equal to root value
    if(currRoot->left!=nullptr && currRoot->left->value!=currRoot->value){
        return false;
    }
    //same condition for right
    if(currRoot->right!=nullptr && currRoot->right->value!=currRoot->value){
        return false;
    }

    //if one of the above conditions doesn't satisy, that means it's a single valued tree
    _count++;

    return true;
}
int findSingleValueTrees(Node* root) {

    int _count = 0;
    findSingleValueTreesUtil(root,_count);
    return _count;
}


int main(){
    /* Let us construct the below tree
            5
          /   \
        4      5
      /  \      \
     4    4      5 */
    Node* root        = newNode(5);
    root->left        = newNode(4);
    root->right       = newNode(5);
    root->left->left  = newNode(4);
    root->left->right = newNode(4);
    root->right->right = newNode(5);

    //5 trees
    cout<<"No of single valued trees:"<<findSingleValueTrees(root)<<"\n";

        /* Let us construct the below tree
            5
          /   \
        5      5
      /  \      \
     5    5      5 */
    root        = newNode(5);
    root->left        = newNode(5);
    root->right       = newNode(5);
    root->left->left  = newNode(5);
    root->left->right = newNode(5);
    root->right->right = newNode(5);

    //6 trees
    cout<<"No of single valued trees:"<<findSingleValueTrees(root);



    return 0;
}

