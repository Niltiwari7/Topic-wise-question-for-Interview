class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> grid(n, vector<int>(n, 1e9));

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            grid[u][v] = w;
            grid[v][u] = w;
        }

        for (int i = 0; i < n; i++)
            grid[i][i] = 0;

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                }
            }
        }

        int cntCity = INT_MAX;
        int cityNo = -1;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if (cnt <= cntCity) {
                cntCity = cnt;
                cityNo = i;
            }
        }
        return cityNo;
    }
};