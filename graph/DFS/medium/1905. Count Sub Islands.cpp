class Solution {
public:
    bool dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& vis) {
        if (i < 0 || j < 0 || i >= grid1.size() || j >= grid1[0].size() || grid2[i][j] == 0 || vis[i][j] == 1) {
            return true;
        }

        vis[i][j] = 1;
        bool isSubIsland = grid1[i][j] == 1;

        
        isSubIsland &= dfs(i + 1, j, grid1, grid2, vis);
        isSubIsland &= dfs(i - 1, j, grid1, grid2, vis);
        isSubIsland &= dfs(i, j + 1, grid1, grid2, vis);
        isSubIsland &= dfs(i, j - 1, grid1, grid2, vis);

        return isSubIsland;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int result = 0;
        int m = grid1.size();
        int n = grid1[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1 && vis[i][j] == 0) {
                    if (dfs(i, j, grid1, grid2, vis)) {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};
