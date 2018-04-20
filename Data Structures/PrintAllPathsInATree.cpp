
/*****Print All Paths in a tree****/

void printAllPaths(Node* curRoot, vector<Node*>& v){
    if(curRoot->left  == nullptr  && curRoot->right==nullptr){
        int len = v.size();
        //vector<Node*>::iterator it;
        for(int i=0;i<len;i++){
            cout << v.at(i)->val << "\t"; 
        }
        cout << endl;
        v.pop_back();
        return;
    }
    if(curRoot->left) v.push_back(curRoot->left);
    printAllPaths(curRoot->left,v);
    if(curRoot->right) v.push_back(curRoot->right);
    printAllPaths(curRoot->right,v);
    
    v.pop_back();
    return;
}

void printAllPaths(Node* root) {
    vector<Node*> v;
    v.push_back(root);
    printAllPaths(root,v);
    return;
}
