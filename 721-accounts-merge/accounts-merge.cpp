class DisjointSet {
public:
    vector<int> size;
    vector<int> parent;
    DisjointSet(int V) {
        parent.resize(V);
        size.resize(V, 1);
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
    }
    int findParent(int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }
    void unionBySize(int u, int v) {
        int p1 = findParent(u);
        int p2 = findParent(v);
        if (p1 == p2) {
            return;
        }
        if (size[p1] >= size[p2]) {
            parent[p2] = p1;
            size[p1] += size[p2];
        } else {
            parent[p1] = p2;
            size[p2] += size[p1];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, int> m;
        DisjointSet Ds(accounts.size());

        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (m.find(accounts[i][j]) == m.end()) {
                    m[accounts[i][j]] = i;
                } else {
                    Ds.unionBySize(m[accounts[i][j]], i);
                }
            }
        }
        vector<vector<string>> emails(accounts.size());

        for (auto i : m) {
            string email = i.first;
            int parent = i.second;
            int ulP = Ds.findParent(parent);

            emails[ulP].push_back(email);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < emails.size(); i++) {
            if (emails[i].size() == 0) {
                continue;
            }
            vector<string> temp;
            sort(emails[i].begin(), emails[i].end());
            temp.push_back(accounts[i][0]);
            for (int j = 0; j < emails[i].size(); j++) {
                temp.push_back(emails[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};