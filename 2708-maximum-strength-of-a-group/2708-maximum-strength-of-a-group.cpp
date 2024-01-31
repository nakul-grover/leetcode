class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> negs, pos;
        for (auto it : nums)
        {
            if (it < 0)
                negs.push_back(it);
            if (it > 0)
                pos.push_back(it);
        }
        long long prod = 1, x = count(nums.begin(), nums.end(), 0);
        sort(negs.begin(), negs.end());
        if (negs.size() <= 1 && pos.size() == 0)
        {
            return *max_element(nums.begin(), nums.end());
        }
        if (negs.size() % 2 == 0)
        {
            for (auto it : negs)
                prod = prod * it;
            for (auto it : pos)
                prod = prod * it;
            return prod;
        }  
        else
        {
            for (int i = 0; i < negs.size() - 1; ++i)
                prod = prod * negs[i];
            for (auto it : pos)
                prod = prod * it;
            return prod;
        }
        return prod;
    }
};