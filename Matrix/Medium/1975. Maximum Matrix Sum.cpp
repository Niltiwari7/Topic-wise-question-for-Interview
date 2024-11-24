class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int count = 0;
        int mini = INT_MAX;
        for (auto& row : matrix) {
            for (auto& col : row) {
                if (col < 0)
                    count++;
                mini = min(mini, abs(col));
                sum += abs(col);
            }
        }
        if (count % 2 == 0) {
            return sum;
        } else {
            return sum - 2 * mini;
        }
    }
};