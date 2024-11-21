class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, int direction) {
        int m = grid.size();
        int n = grid[0].size();
        while (i >= 0 && j >= 0 && i < m && j < n) {
            if (grid[i][j] == 1 || grid[i][j] == 2) {
                break; 
            }
            if (grid[i][j] == -1) {
                grid[i][j] = 0; 
            }

        
            if (direction == 0) i++;       // Down
            else if (direction == 1) j++;  // Right
            else if (direction == 2) i--;  // Up
            else if (direction == 3) j--;  // Left
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Initialize the grid: -1 = unguarded, 1 = guard, 2 = wall
        vector<vector<int>> grid(m, vector<int>(n, -1));

        // Place guards and walls in the grid
        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = 1; // Guard
        }
        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = 2; // Wall
        }

        // Propagate guard visibility in all four directions
        for (auto& guard : guards) {
            int x = guard[0];
            int y = guard[1];
            dfs(x + 1, y, grid, 0); // Down
            dfs(x, y + 1, grid, 1); // Right
            dfs(x - 1, y, grid, 2); // Up
            dfs(x, y - 1, grid, 3); // Left
        }

        
        int count = 0;
        for (auto& row : grid) {
            for (int cell : row) {
                if (cell == -1) {
                    count++;
                }
            }
        }

        return count;
    }
};
