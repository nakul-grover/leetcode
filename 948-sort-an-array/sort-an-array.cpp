#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> v1(n1);
        vector<int> v2(n2);

        for (int i = 0; i < n1; i++) {
            v1[i] = nums[left + i];
        }
        for (int i = 0; i < n2; i++) {
            v2[i] = nums[mid + 1 + i];
        }

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (v1[i] <= v2[j]) {
                nums[k] = v1[i];
                i++;
            } else {
                nums[k] = v2[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            nums[k] = v1[i];
            i++;
            k++;
        }

        while (j < n2) {
            nums[k] = v2[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
