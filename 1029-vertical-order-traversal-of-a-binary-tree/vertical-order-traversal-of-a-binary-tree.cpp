class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> m;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<TreeNode*, pair<int, int>> front = q.front();
                q.pop();
                TreeNode* node = front.first;
                int hd = front.second.first;
                int vd = front.second.second;
                m[hd][vd].insert(front.first->val);
                if (node->left) {
                    q.push({node->left, {hd - 1, vd + 1}});
                }
                if (node->right) {
                    q.push({node->right, {hd + 1, vd + 1}});
                }
            }
        }

        vector<vector<int>> ans;
        for (auto i : m) {
            vector<int> temp;
            for (auto j : i.second) {
                for (int val : j.second) {
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
