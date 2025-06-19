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
    int pre = 0;
    TreeNode* constructTree(vector<int>&preorder, unordered_map<int,int>&m, int instart,int inend){
        if(instart>inend){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[pre++]);
        int inindex = m[root->val];

        root->left = constructTree(preorder,m, instart, inindex-1);
        root->right = constructTree(preorder,m, inindex+1, inend);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
       return  constructTree(preorder,m,0,inorder.size()-1);
    }
};