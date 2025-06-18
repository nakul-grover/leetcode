/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void makeParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& m) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front->left) {
                m[front->left] = front;
                q.push(front->left);
            }
            if (front->right) {
                m[front->right] = front;
                q.push(front->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> m;
        makeParent(root, m);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        int lvl = 0;

        q.push(target);
        visited[target] = true;

        while (!q.empty()) {
            int size = q.size();
            if (lvl == k) break;
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                if (front->left && !visited[front->left]) {
                    visited[front->left] = true;
                    q.push(front->left);
                }
                if (front->right && !visited[front->right]) {
                    visited[front->right] = true;
                    q.push(front->right);
                }
                if (m.find(front) != m.end() && !visited[m[front]]) {
                    visited[m[front]] = true;
                    q.push(m[front]);
                }
            }
            lvl++;
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
