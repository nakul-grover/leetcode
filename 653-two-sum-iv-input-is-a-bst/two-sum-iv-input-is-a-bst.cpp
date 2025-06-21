class BstIterator {
public:
    bool reverse;
    stack<TreeNode*> s;

    BstIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    void pushAll(TreeNode* node) {
        while (node) {
            s.push(node);
            node = reverse ? node->right : node->left;
        }
    }

    bool hasNext() {
        return !s.empty();
    }

    int next() {
        TreeNode* temp = s.top();
        s.pop();
        if (reverse) {
            pushAll(temp->left);
        } else {
            pushAll(temp->right);
        }
        return temp->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int target) {
        if (!root) return false;

        BstIterator l(root, false);
        BstIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while (i < j) {
            if (i + j == target) return true;
            else if (i + j < target) i = l.next();
            else j = r.next();
        }
        return false;
    }
};
