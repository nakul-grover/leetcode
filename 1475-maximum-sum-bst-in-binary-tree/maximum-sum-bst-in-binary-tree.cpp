class Box {
public:
    int min, max, sum;
    bool isBST;
    Box() {
        min = INT_MAX;
        max = INT_MIN;
        sum = 0;
        isBST = 1;
    }
};
class Solution {
public:
    Box* maxSum(TreeNode* root, int& totalSum) {
        if (!root)
            return new Box();
        else {
            Box* lefthead = maxSum(root->left, totalSum);
            Box* righthead = maxSum(root->right, totalSum);
            if (lefthead->isBST && righthead->isBST &&
                lefthead->max < root->val && righthead->min > root->val) {
                Box* head = new Box();
                head->sum = root->val + lefthead->sum + righthead->sum;
                head->min = min(root->val, lefthead->min);
                head->max = max(root->val, righthead->max);
                totalSum = max(totalSum, head->sum);
                return head;
            } else {
                Box* curr = new Box();
                curr->isBST = 0;
                return curr;
            }
        }
    }
    int maxSumBST(TreeNode* root) {
        int totalSum = 0;
        maxSum(root, totalSum);
        return totalSum;
    }
};