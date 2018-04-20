#include<iostream>
#include<stack>

using namespace std;

class Node
{
    public:
    int data;
    struct Node *left, *right;
};

Node* newNode(int val){
    Node* node = new Node;
    node->data = val;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void postOrderIterative(Node *root) {
  if (!root) return;
  stack<Node*> s;
  s.push(root);
  Node *prev = NULL;
  while (!s.empty()) {
    Node *curr = s.top();
    // traversing down the tree
    if (!prev || prev->left == curr || prev->right == curr) {
      if (curr->left) {
        s.push(curr->left);
      } else if (curr->right) {
        s.push(curr->right);
      } else {
        cout << curr->data << " ";
        s.pop();
      }
    }
    // traversing up the tree from the left
    else if (curr->left == prev) {
      if (curr->right) {
        s.push(curr->right);
      } else {
        cout << curr->data << " ";
        s.pop();
      }
    }
    // traversing up the tree from the right
    else if (curr->right == prev) {
      cout << curr->data << " ";
      s.pop();
    }
    prev = curr;  // save previously traversed node
  }
}

int main(){

    //Tree
    Node* root = nullptr;
    root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);

    //Post-order Traversal - iterative
    cout<<"Post order traversal of binary tree is :\n";
    cout<<"[";
    postOrderIterative(root);
    cout<<"]";
    return 0;
}
