class Solution {
public:
    vector<string> roman =
        { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
    vector<int> number = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };

    string intToRoman(int num) {
        string ans = "";
        
        while (num > 0) {
            auto it = lower_bound(number.begin(), number.end(), num);
            int index = it - number.begin() - (it == number.end() || *it != num);
            ans += roman[index];
            num -= number[index];
        }
        
        return ans;
    }
};
