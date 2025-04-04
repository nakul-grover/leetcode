class Solution {
public:

   
    void merge(vector<int>&nums,int start,int mid,int end){

        int n1 = mid-start+1;
        int n2 = end - mid;

        vector<int>nums1(n1);
        vector<int>nums2(n2);


        for(int i=0;i<n1;i++){
            nums1[i] = nums[start+i];
        }
        for(int i=0;i<n2;i++){
            nums2[i] = nums[mid+1+i];
        }
        
        int i = 0;
        int j = 0;
        int k = start;

        while(i<n1 && j<n2){
            if(nums1[i] >= nums2[j]){
                nums[k++] = nums2[j++];
            }
            else{
                nums[k++] = nums1[i++];
            }
        }

        while(i<n1){
            nums[k++] = nums1[i++];
        }

        while(j<n2){
            nums[k++] = nums2[j++];
        }
    }

    void mergeSort(vector<int>&nums,int start,int end){
        if(start<end){
           int mid = start + (end-start)/2;
           mergeSort(nums,start,mid);
           mergeSort(nums,mid+1,end);
           merge(nums,start,mid,end);
        }
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};