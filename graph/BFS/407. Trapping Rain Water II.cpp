class Solution {
public:
    typedef pair<int, pair<int, int>> PP;
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<PP, vector<PP>, greater<>> pq;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        // left most column and right most column
        for (int row = 0; row < m; row++) {
            for (int col : {0, n - 1}) {
                pq.push({heightMap[row][col], {row, col}});
                vis[row][col] = true;
            }
        }

        // top most row and bottom most row {0,n-1}
        for (int col = 0; col < n; col++) {
            for (int row : {0, m - 1}) {
                pq.push({heightMap[row][col], {row, col}});
                vis[row][col] = true;
            }
        }

        int water = 0;
        while (!pq.empty()) {
            auto [curr, cord] = pq.top();
            pq.pop();
            int x = cord.first;
            int y = cord.second;
            for (auto d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny]) {
                    continue;
                }
                water += max(curr - heightMap[nx][ny], 0);
                pq.push({max(curr, heightMap[nx][ny]), {nx, ny}});
                vis[nx][ny] = true;
            }
        }
        return water;
    }
};