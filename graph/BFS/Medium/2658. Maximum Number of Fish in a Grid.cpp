class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int solve(int row, int col, vector<vector<bool>>& vis,
              vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = true;

        int result = 0;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            result += grid[x][y];

            for (auto d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx >= 0 && nx < grid.size() && ny >= 0 &&
                    ny < grid[0].size() && !vis[nx][ny] && grid[nx][ny] != 0) {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }

        return result;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxi = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<bool>> vis(m, vector<bool>(n, false));
                if (grid[i][j] != 0 && !vis[i][j]) {
                    maxi = max(maxi, solve(i, j, vis, grid));
                }
            }
        }

        return maxi;
    }
};
