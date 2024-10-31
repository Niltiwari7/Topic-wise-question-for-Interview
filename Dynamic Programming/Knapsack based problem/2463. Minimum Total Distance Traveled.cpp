class Solution {
public:
    long long dp[101][101][101];

    long long solve(int i, int j, vector<int>& robot, vector<vector<int>>& factory, int limit) {
        if (i >= robot.size()) {
            return 0;  // All robots have been placed
        }
        if (j >= factory.size()) {
            return LLONG_MAX;  // No more factories left
        }
        
        if (dp[i][j][limit] != -1) {
            return dp[i][j][limit];
        }

        long long skip = LLONG_MAX;
        if (j + 1 < factory.size()) {  
            skip = solve(i, j + 1, robot, factory, factory[j + 1][1]);
        }
        long long res = skip;

        if (limit > 0) {
            long long takeDistance = abs(robot[i] - factory[j][0]);
            long long take = solve(i + 1, j, robot, factory, limit - 1);
            if (take != LLONG_MAX) {
                res = min(res, take + takeDistance);
            }
        }
        
        return dp[i][j][limit] = res;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, robot, factory, factory[0][1]);
    }
};
