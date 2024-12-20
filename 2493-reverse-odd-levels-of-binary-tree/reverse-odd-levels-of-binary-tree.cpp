class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int count = 0;
        vector<TreeNode*> nodes;
        
        while (!q.empty()) {
            int s = q.size();
            
            for (int k = 0; k < s; k++) {
                TreeNode* front = q.front();
                q.pop();

                if (count % 2 == 0) {
                    if (front->left) {
                        nodes.push_back(front->left);
                    }
                    if (front->right) {
                        nodes.push_back(front->right);
                    }
                }

                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            
            if(count % 2 == 0) {
                int i = 0;
                int j = nodes.size() - 1;
                while (i < j) {
                    int temp = nodes[i]->val;
                    nodes[i]->val = nodes[j]->val;
                    nodes[j]->val = temp;
                    i++;
                    j--;
                }
            }

            nodes.clear();
            count++;
        }
        
        return root;
    }
};
