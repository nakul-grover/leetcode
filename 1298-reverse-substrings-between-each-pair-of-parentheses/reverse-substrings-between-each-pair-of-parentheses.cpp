class Solution {
public:
    string reverseParentheses(string s) {
        return reverseParenthesesHelper(s, 0).first;
    }

private:
    pair<string, int> reverseParenthesesHelper(const string& s, int start) {
        string current="";
        int i = start;

        while (i < s.size()) {
            if (s[i] == '(') {
                auto result = reverseParenthesesHelper(s, i + 1);
                string temp = result.first;
                reverse(temp.begin(), temp.end());
                current += temp;
                i = result.second;
            } else if (s[i] == ')') {
                return {current, i + 1};
            } else {
                current += s[i];
                i++;
            }
        }

        return {current, i};
    }
};
