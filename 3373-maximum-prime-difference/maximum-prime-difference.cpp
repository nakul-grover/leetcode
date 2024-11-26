class Solution {
public:

    bool isPrime(int n) {
        if(n == 1){
            return false;
        }
        int i=2;
        while(i<=sqrt(n)){
           if(n%i == 0){
            return false;
        }
        i++;
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int first = -1;
        int second = -1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(isPrime(nums[i])){
                first = i;
                break;
            }
        }
        for(int i= n-1 ;i >= 0 ;i--){
            if(isPrime(nums[i])){
                second = i;
                break;
            }
        }

        if(first == -1 && second == -1){
            return 0;
        }

        if(first  == -1 || second == -1){
            return 0;
        }

        return second -first;
    }
};