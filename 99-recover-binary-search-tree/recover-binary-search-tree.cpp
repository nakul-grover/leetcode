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
    TreeNode* first;
    TreeNode* mid;
    TreeNode* end;
    TreeNode* prev;
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        if(prev != NULL && root->val < prev->val){
            if(first == NULL){
                first = prev;
                mid = root;
            }
            else{
                end = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(end){
            int temp  = first->val;
            first->val = end->val;
            end->val = temp;
            return;
        }
          int temp = first->val;
          first->val = mid->val;
          mid->val = temp;
          return ;
        
    }
};