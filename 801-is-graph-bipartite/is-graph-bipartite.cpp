class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (color[i] != -1) continue;

            color[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int nbr : graph[node]) {
                    if (color[nbr] == -1) {
                        color[nbr] = 1 - color[node];
                        q.push(nbr);
                    } else if (color[nbr] == color[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
