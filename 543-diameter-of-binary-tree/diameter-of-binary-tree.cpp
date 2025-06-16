class Solution {
public:
    pair<int,int> solve(TreeNode* root){
        if(!root){
            return {0, 0};
        }

        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);

        int currentHeight = 1 + max(left.second, right.second);
        int diameterThroughRoot = left.second + right.second;
        int maxDiameter = max({left.first, right.first, diameterThroughRoot});

        return {maxDiameter, currentHeight};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first;
    }
};
