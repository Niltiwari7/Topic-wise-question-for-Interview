class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowSum = accumulate(begin(grid[0]), end(grid[0]), 0LL);
        long long secondRowRemainSum = 0;
        long long res = LONG_LONG_MAX;
        for (int col = 0; col < grid[0].size(); col++) {
            firstRowSum -= grid[0][col];
            long long bestofRobot2 = max(firstRowSum, secondRowRemainSum);
            res = min(res, bestofRobot2);
            secondRowRemainSum += grid[1][col];
        }
        return res;
    }
};