/**
Author:Santosh Tandrothu
Date:2/10/2019
Run: O(n)
Space: O(n)
**/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



bool findPath(TreeNode* root, vector<int>& path, int val){
    //root null..sorry send me a valid root
    if(root == nullptr)return false;

    //Push the current node into the path
    path.push_back(root->val);

    //Bingo! I found the element you are looking for...mission accomplished
    if(root->val==val){return true;}

    //Let me check in the left subtree or right subtree and tell you the result
    if((root->left&&findPath(root->left,path,val)) || (root->right&&findPath(root->right,path,val))){
        return true;
    }

    //The val is neither in left or right subtree...let's kick it out of our path..NO use to us!
    path.pop_back();
    //can't find what you are looking for...Sorry!
    return false;
}

int Solution::lca(TreeNode* root, int val1, int val2){

    if(root==nullptr)return -1;
        //consider -root=4 val1=4 val2=4
    if(root->val==val1 && root->val==val2){return val1;}

    vector<int> path1,path2;
    //Find and build the path for val1 and val2 if both nodes exist in tree
    if(!findPath(root,path1,val1)||!findPath(root,path2,val2)){
        return -1;
    }

    //int loop_size = min(path1.size(),path2.size());

    for(int i=0;i<int(v1.size())&&i<int(v2.size());i++){
        if(path1[i]!=path2[i]){
            break;
        }
    }
    return path1[i-1];

}

/**********Run: O(n) and Space:O(h)*******/

bool findPath(TreeNode* root, int val){
    if(root==nullptr){return false;}
    if(root->val == val){return true;}
    return findPath(root->left,val) || findPath(root->right,val);
}

TreeNode* LCA(TreeNode* root, int val1, int val2){
    if(root==nullptr)return root;
    if(root->val == val1 || root->val==val2){return root;}
    TreeNode* L = LCA(root->left,val1,val2);
    TreeNode* R = LCA(root->right,val1,val2);.2
    if(L&&R){return root;} //if val1 and val2 are left and right side of root - find(1,3)->ans:2
    return L?L:R; //if val1 is present in the left subtree and val2 is present in the right subtree find(3,5)->4
}
int findLCA(TreeNode* root, int val1,int val2){
    if(root==nullptr){return -1;}
    TreeNode* ans = LCA(root,val1,val2);
    if(!ans){return -1;}
    return ans->val;
}
