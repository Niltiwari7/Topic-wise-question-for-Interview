class Solution {
public:
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] == 0) {
            return 0;
        }

        int originalVal = grid[i][j];
        grid[i][j] = 0;
        int maxGold = 0;

        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            maxGold = max(maxGold, dfs(grid, new_i, new_j));
        }

        grid[i][j] = originalVal;
        return originalVal + maxGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxGold = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, dfs(grid, i, j));
                }
            }
        }

        return maxGold;
    }
};
