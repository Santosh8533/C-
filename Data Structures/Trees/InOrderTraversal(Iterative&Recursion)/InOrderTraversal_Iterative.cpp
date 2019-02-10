/**
    Author: Santosh Tandrothu
    Date: 2/10/2019
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
vector<int> Solution::inorderTraversal(TreeNode* root) {
     TreeNode* curr = root;
     stack<TreeNode*> s;
     vector<int> res;

     if(root==nullptr) return res;
     //left nodes
     while(curr!=nullptr){
         s.push(curr);
         curr = curr->left;
     }

     //left and right
     while(!s.empty()){
         curr = s.top();
         res.push_back(curr->val);
         s.pop();

         if(curr->right){
            curr = curr->right;

            while(curr!=nullptr){
                s.push(curr);
                curr = curr->left;
            }
         }
     }
     return res;
}
