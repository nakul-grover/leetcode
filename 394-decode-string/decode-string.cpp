class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return helper(s, i);
    }

    string helper(string &s, int &i) {
        string result = "";
        int num = 0;

        while (i < s.size()) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            else if (s[i] == '[') {
                i++;
                string temp = helper(s, i);

                while (num--) {
                    result += temp;
                }

                num = 0;
            }
            else if (s[i] == ']') {
                i++;
                return result;
            }
            else {
                result += s[i];
                i++;
            }
        }

        return result;
    }
};