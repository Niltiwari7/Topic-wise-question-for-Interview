// Brute force approach
class Solution {
public:
    vector<vector<int>>dir = {{0,1},{1,0},{-1,0},{0,-1}};
    int DFS(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis){
        vis[i][j] = true;
        int res = 1;
        for(auto d:dir){
            int nx = i+d[0];
            int ny = j+d[1];
            if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid.size() && !vis[nx][ny] && grid[nx][ny]==1){
                vis[nx][ny]=true;
                res += DFS(nx, ny, grid, vis);

            }
        }
        return res;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        int maxArea = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    flag = false;
                    grid[i][j] = 1;
                    int maxi = 0;
                    vector<vector<bool>> vis(n, vector<bool>(n, false));
                    for (int x = 0; x < n; x++) {
                        for (int y = 0; y < n; y++) {
                            if (grid[x][y] == 1 && !vis[x][y]) {
                                maxi = max(maxi, DFS(x, y, grid, vis));
                            }
                        }
                    }
                    maxArea = max(maxi, maxArea);
                    grid[i][j]=0;
                }
            }
        }
        if(flag)return n*n;
        return maxArea;
    }
};

// Better approach
class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int DFS(int i, int j, vector<vector<int>>& grid,
            vector<vector<bool>>& vis) {
        vis[i][j] = 1;
        int res = 1;
        for (auto d : dir) {
            int nx = i + d[0];
            int ny = j + d[1];
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid.size() &&
                grid[nx][ny] == 1 && !vis[nx][ny]) {
                vis[nx][ny] = true;
                res += DFS(nx, ny, grid, vis);
            }
        }
        return res;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int largest = 0;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    largest = max(largest, DFS(i, j, grid, vis));
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    grid[i][j] = 1;
                    vector<vector<bool>> nvis(n, vector<bool>(n, false));
                    largest = max(largest, DFS(i, j, grid, nvis));
                    grid[i][j] = 0;
                }
            }
        }

        return largest;
    }
};


// Optimal approach
class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int DFS(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, int u_id, unordered_map<int, int>& mp) {
        vis[i][j] = true;
        grid[i][j] = u_id;  
        int res = 1;

        for (auto d : dir) {
            int nx = i + d[0];
            int ny = j + d[1];
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() &&
                grid[nx][ny] == 1 && !vis[nx][ny]) {
                res += DFS(nx, ny, grid, vis, u_id, mp);
            }
        }
        return res;
    }

    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> mp;
        int n = grid.size();
        int u_id = 2; 
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        int largest = 0;

      
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int size = DFS(i, j, grid, vis, u_id, mp);
                    mp[u_id] = size; 
                    largest = max(largest, size); 
                    u_id++;
                }
            }
        }

       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uniqueComponents;
                    int res = 1;  

                
                    for (auto d : dir) {
                        int nx = i + d[0];
                        int ny = j + d[1];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] > 1) {
                            uniqueComponents.insert(grid[nx][ny]);  
                        }
                    }

                  
                    for (int id : uniqueComponents) {
                        res += mp[id];
                    }

                    largest = max(largest, res);
                }
            }
        }

        return largest;
    }
};