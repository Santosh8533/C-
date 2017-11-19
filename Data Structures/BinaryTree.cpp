# include <iostream>
# include <cstdlib>
using namespace std;


class Node
{
    public:
    int value;
    Node *left;
    Node *right;
};


class BST
{
    public:
        Node* root;
        Node* createNode(int);
        void insertNode(Node*, Node*);
        void insertNode(Node*);
        void del(int);
        void display(Node*, int);
        BST()
        {
            root = NULL;
        }
};

Node* BST::createNode(int value){
    Node* node = new Node;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

void BST::insertNode(Node* node, Node* currentRoot){
    if(currentRoot == nullptr){
        currentRoot->left = node;
        return;
    }
    if(node->value < currentRoot->value){
        insertNode(node,currentRoot->left);
    }
    else if(node->value > currentRoot->value){
        insertNode(node, currentRoot->right);
    }
}
void BST::insertNode(Node* node){
    if(root == nullptr){
        root = node;
        cout << "Root created->" << root->value << endl;
        return;
    }
    if(node->value < root->value){
        insertNode(node,&root->left);
    }
    
    else if (node->value < root->value){
        insertNode(node,&root->right);
    }
}

int main()
{
    int choice, value, node;
    BST bt;
    while(1){
        cout << "1. Insert \n 2. Delete \n 3.Display \n";
        cout << "Enter your choice" << endl;
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter the node to be inserted\n" << endl;
                cin >> value;
                Node* node = bt.createNode(value);
                cout << "Node created->" << node->value << endl;
                bt.insertNode(node);
                break;

        }
        exit(0);
    }
    return 0;
}
