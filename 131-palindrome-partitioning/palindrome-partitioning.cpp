class Solution {
public:

    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void solve(string s, int index, vector<vector<string>>& ans, vector<string>& temp) {
        if (index >= s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = index + 1; i <= s.size(); i++) {
            if (isPalindrome(s.substr(index, i - index))) {
                temp.push_back(s.substr(index, i - index));
                solve(s, i, ans, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, 0, ans, temp);
        return ans;
    }
};
