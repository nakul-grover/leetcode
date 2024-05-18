class Solution {
public:
    int needCoins(TreeNode* r, int& steps){
        if(r==nullptr) return 0;
        int c1=needCoins(r->left, steps);
        int c2=needCoins(r->right, steps);
        steps+=(abs(c1)+abs(c2));
        return c1+c2+(r->val-1);
    }

    int distributeCoins(TreeNode* root) {
        int steps=0;
        needCoins(root, steps);
        return steps;
    }
};