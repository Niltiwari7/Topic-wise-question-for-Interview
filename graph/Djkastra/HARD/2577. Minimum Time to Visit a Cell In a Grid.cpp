class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    int minimumTime(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        int m = grid.size();
        int n = grid[0].size();
         if (grid[1][0]>1 && grid[0][1]>1)  return -1;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[0][0] = true;
        pq.push({0, {0, 0}});
        
        while (!pq.empty()) {
            auto [t, cord] = pq.top();
            pq.pop();
            int x = cord.first;
            int y = cord.second;
            
            if (x == m - 1 && y == n - 1) {
                return t;
            }
            vis[x][y] = true;
            for (auto d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny]) {
                    int wait = (grid[nx][ny] - t) % 2 == 0 ? 1 : 0;
                    int new_time = max(grid[nx][ny] + wait, t + 1);
                    pq.push({new_time, {nx, ny}});
                    vis[nx][ny] = true;
                }
            }
        }
        return -1;
    }
};
