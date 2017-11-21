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
        Node* insertNode(Node*, Node*);
        void insertNode(Node*);
        void preorder(Node*);
        void del(int);
        Node* del(Node*,Node*);
        Node* findNode(int);
        void display();
        BST()
        {
            root = NULL;
        }
};
/**delete a node
1. There are two ways:
    a. Replacing the smallest node on the right side subtree of the node
    b. Replacing the largest node on the left side subtree of the node

2. delete(int value)
    a. node = find(value);
    b. replacenode = delete(node,root)
    c. node->value = replacenode->value
    d. replacenode = nullptr;
***/

Node* BST::findNode(int nodeValue){
   // if(root==NULL){cout <<"No tree" << endl;return nullptr;}
    Node *temp = root;
    while(temp!=nullptr){
        if(nodeValue == temp->value){
            return temp;
        }
        else if(nodeValue < temp->value){
            temp=temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return nullptr;
}

/**Delete a node**/
void BST::del(int nodeValue){
    Node *node = findNode(nodeValue);
    if(node == nullptr){return;}
    Node *replacementNode = delete(node);
    node->value = replacementNode->value;
    replacementNode = nullptr;
    delete replacementNode;
}

Node* BST::del(Node* currentRoot){
    
    /**
    1. is it a leaf node?
    2. one child
    3. two child
    ***/
    if(currentRoot->left && currentRoot->right == nullptr){return currentRoot;}
    
    
    //One chid
    if(currentRoot->left == nullptr && currentRoot->right!=nullptr){
        currentRoot = currentRoot->right;
    }
    else if(currentRoot->left != nullptr && currentRoot->right==nullptr){
        
    }

    //3. two children
    currentRoot = currentRoot->left;
    while(currentRoot->right!=nullptr){
        currentRoot=currentRoot->right;
    }
    return currentRoot;
}

Node* BST::createNode(int value){
    Node* node = new Node;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* BST::insertNode(Node* node, Node* currentRoot){
    if(currentRoot == nullptr){
        return node;
    }

    if(node->value < currentRoot->value){
        currentRoot->left = insertNode(node, currentRoot->left);
    }

    else if(node->value > currentRoot->value){
        currentRoot->right = insertNode(node, currentRoot->right);
    }
    else{
        cout<< "Duplication avoided" << endl;
        return nullptr;
    }

}

void BST::display(){
    preorder(root);
}

void BST::preorder(Node *currentRoot){
    if(currentRoot==nullptr){
        return;
    }
    cout<< currentRoot->value << endl;
    preorder(currentRoot->left);
    preorder(currentRoot->right);
}
void BST::insertNode(Node* node){
    if(root == nullptr){
        root = node;
        cout << "Root created->" << root->value << endl;
        return;
    }
    insertNode(node,root);
}

int main()
{
    int choice, value;
    BST bt;
    Node* node = nullptr;
    while(1){

        cout << "1.Insert\n2.Delete\n3.Display\n4.Find\n5.Exit\n";
        cout << "Enter your choice" << endl;
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter the node to be inserted\n" << endl;
                cin >> value;
                node = bt.createNode(value);
                cout << "Node created->" << node->value << endl;
                bt.insertNode(node);
                break;
            case 3:
                bt.display();
            case 5:
                exit(0);

        }
        //exit(0);
    }
    return 0;
}
