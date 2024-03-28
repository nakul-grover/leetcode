class Solution {
public:
    pair<int,int> helper(TreeNode* node){
        if(!node) return {0,0};
        pair<int,int> leftSide=helper(node->left);
        pair<int,int> rightSide=helper(node->right);
        int pick=node->val+leftSide.second+rightSide.second;
        int notPick=max(leftSide.first,leftSide.second)+max(rightSide.first,rightSide.second);
    return {pick,notPick};
    }

    int rob(TreeNode* root) {
        if(!root) return 0;
        if(root and !root->left and !root->right) return root->val;
        pair<int,int> ans=helper(root);
        int result=max(ans.first,ans.second);
    return result;
    }
};