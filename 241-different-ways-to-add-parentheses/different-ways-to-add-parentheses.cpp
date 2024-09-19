class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> solve(string s) {
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }

        vector<int> ans;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int> left = solve(s.substr(0, i));
                vector<int> right = solve(s.substr(i + 1));

                for (int l : left) {
                    for (int r : right) {
                        if (s[i] == '+') {
                            ans.push_back(l + r);
                        } else if (s[i] == '-') {
                            ans.push_back(l - r);
                        } else {
                            ans.push_back(l * r);
                        }
                    }
                }
            }
        }

        if (ans.empty()) {
            ans.push_back(stoi(s));
        }

        memo[s] = ans;
        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};
