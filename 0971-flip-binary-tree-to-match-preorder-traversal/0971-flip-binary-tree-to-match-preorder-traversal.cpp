/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int i=0;
    bool dfs(TreeNode*root,vector<int>voyage,vector<int>&ans){
        if(root==NULL){
            return true;
        }
        if(root->val!=voyage[i++]){
            return false;
}
        if(root->left!=NULL && root->left->val!=voyage[i]){
            ans.push_back(root->val);
            return dfs(root->right,voyage,ans) && dfs(root->left,voyage,ans);
        }
        else{
            return dfs(root->left,voyage,ans) && dfs(root->right,voyage,ans);
        }
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
      vector<int>ans;
       if(dfs(root,voyage,ans)){
           return ans;
       }
        else{
            ans.clear();
            ans.push_back(-1);
            return ans;
        }
    }
};