class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<pair<int, pair<int, int>>> v;
        for (int i = 0; i < n; ++i) {
            v.push_back({tasks[i][0], {tasks[i][1], i}});
        }
        sort(v.begin(), v.end());

        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        long long time = 0;
        int i = 0;

        while (i < n || !pq.empty()) {
            while (i < n && v[i].first <= time) {
                pq.push({v[i].second.first, v[i].second.second});
                i++;
            }

            if (!pq.empty()) {
                auto p = pq.top();
                pq.pop();
                time += p.first;
                ans.push_back(p.second);
            } else {
                time = v[i].first;
            }
        }

        return ans;
    }
};
