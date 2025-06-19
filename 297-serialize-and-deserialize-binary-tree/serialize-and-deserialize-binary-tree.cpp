/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "#,";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            
            if (front) {
                s += to_string(front->val) + ",";
                q.push(front->left);
                q.push(front->right);
            } else {
                s += "#,";
            }
        }
        return s;
    }

    TreeNode* deserialize(string data) {
        if (data == "#,") return NULL;

        vector<string> nodes;
        string temp = "";
        for (char ch : data) {
            if (ch == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += ch;
            }
        }

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        int index = 1;

        while (!q.empty() && index < nodes.size()) {
            TreeNode* front = q.front();
            q.pop();

            if (nodes[index] != "#") {
                front->left = new TreeNode(stoi(nodes[index]));
                q.push(front->left);
            } else {
                front->left = NULL;
            }
            index++;

            if (index < nodes.size() && nodes[index] != "#") {
                front->right = new TreeNode(stoi(nodes[index]));
                q.push(front->right);
            } else {
                front->right = NULL;
            }
            index++;
        }
        return root;
    }
};
