class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sum = 0, sqrSum = 0;
        long long n = grid.size();
        long long total = n * n;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sum += grid[i][j];
                sqrSum += (long long)grid[i][j] * grid[i][j];
            }
        }

        long long sumDiff = sum - total * (total + 1) / 2;
        long long sqrDiff = sqrSum - total * (total + 1) * (2 * total + 1) / 6;

        int repeat = (sqrDiff / sumDiff + sumDiff) / 2;
        int missing = (sqrDiff / sumDiff - sumDiff) / 2;

        return {repeat, missing};
    }
};
