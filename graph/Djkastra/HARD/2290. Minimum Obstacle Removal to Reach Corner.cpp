class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> adj(m, vector<int>(n, INT_MAX));
        adj[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            auto [dist, curr] = pq.top();
            pq.pop();
            int x = curr.first;
            int y = curr.second;
            if (x == m - 1 && y == n - 1) {
                return dist;
            }
            for (auto d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int newDist = dist + grid[nx][ny];
                    if (newDist < adj[nx][ny]) {
                        adj[nx][ny] = newDist;
                        pq.push({newDist, {nx, ny}});
                    }
                }
            }
        }
        return adj[m - 1][n - 1];
    }
};