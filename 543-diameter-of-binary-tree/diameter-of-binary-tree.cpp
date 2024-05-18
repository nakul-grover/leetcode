class Solution {
public:
     int res=0;
     int height(TreeNode* root){
     if(root==NULL)
     return 0;
     int lh=height(root->left);
     int rh=height(root->right);
     res=max(res,lh+rh+1);
     return 1+max(rh,lh);
 }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return res-1;
    }
};