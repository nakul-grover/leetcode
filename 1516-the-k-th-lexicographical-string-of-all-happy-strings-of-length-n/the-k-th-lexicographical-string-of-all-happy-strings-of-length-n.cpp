class Solution {
public:
    void getAllHappyStrings(int n, vector<string>& strings, string s) {
        if (s.size() == n) {
            strings.push_back(s);
            return;
        }
        for (char i = 'a'; i <= 'c'; i++) {
            if (s.size() == 0 || s[s.size() - 1] != i) {
                string temp = s + i;
                getAllHappyStrings(n, strings, temp);
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> strings;
        getAllHappyStrings(n, strings, "");
        
        if (strings.size() >= k) {
            return strings[k - 1];
        }
        
        return "";
    }
};
