class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        
        pq.push({0, {0, 0}});
        result[0][0] = 0;

        while (!pq.empty()) {
            auto [cost, cord] = pq.top();
            pq.pop();
            auto [x, y] = cord;

            if (x == m - 1 && y == n - 1) {
                return cost;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }

                int new_cost = cost + ((grid[x][y] - 1) != i ? 1 : 0);


                if (new_cost < result[nx][ny]) {
                    result[nx][ny] = new_cost;
                    pq.push({new_cost, {nx, ny}});
                }
            }
        }

        return 0; 
    }
};
