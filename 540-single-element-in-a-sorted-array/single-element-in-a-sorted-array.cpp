class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int n = nums.size();
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int key = nums[mid];
            if (!(mid - 1 >= 0 && nums[mid - 1] == key) &&
                !(mid + 1 < n && nums[mid + 1] == key)) {
                return key;
            } else {
                if ((mid + 1 < n && nums[mid + 1] == nums[mid] &&
                     mid % 2 == 1) ||
                    (mid - 1 >= 0 && nums[mid] == nums[mid - 1] && mid % 2 == 0)){
                    end = mid-1;
                }
                else {
                    start = mid + 1;
                }
            }
        } 
        return -1;
    }
};