class Solution {
public:
    bool isPrime(int num) {
        if (num == 1) return false;
        for (int divisor = 2; divisor <= sqrt(num); divisor++) {
            if (num % divisor == 0) {
                return false;
            }
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> pair;
        int prev = -1;

        for (int num = left; num <= right; num++) {
            if (!isPrime(num)) continue;

            if (prev == -1) {
                prev = num;
                continue;
            }

            int dif = num - prev;

            if (dif <= 2) {
                return {prev, num};
            }

            if (pair.empty() || dif < pair[1] - pair[0]) {
                pair = {prev, num};
            }

            prev = num;
        }

        return pair.empty() ? vector<int>{-1, -1} : pair;
    }
};