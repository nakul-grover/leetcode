class Solution {
public:
    void solve(int i, vector<int>& candidates, int target, vector<int>& path, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        if (i == candidates.size() || target < 0) return;

        if (candidates[i] <= target) {
            path.push_back(candidates[i]);
            solve(i, candidates, target - candidates[i], path, res); 
            path.pop_back();  
        }

        solve(i + 1, candidates, target, path, res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

        vector<int> path;
        vector<vector<int>> res;

        solve(0, candidates, target, path, res);
        return res;
    }
};
