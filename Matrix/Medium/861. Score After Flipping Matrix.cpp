class Solution {
public:
    int m, n;
    
    void flipRow(vector<vector<int>>& grid, int row) {
        for (int col = 0; col < n; col++) {
            grid[row][col] ^= 1;
        }
    }

    bool isGreater(vector<vector<int>>& grid, int col) {
        int countZero = 0;
        int countOne = 0;
        for (int row = 0; row < m; row++) {
            if (grid[row][col] == 0) {
                countZero++;
            } else {
                countOne++;
            }
        }
        return countOne <= countZero;
    }

    void flipCol(vector<vector<int>>& grid, int col) {
        for (int row = 0; row < m; row++) {
            grid[row][col] ^= 1;
        }
    }

    int binaryToDecimal(vector<vector<int>>& grid, int row) {
        int val = 0;
        int k = 0;
        for (int col = n - 1; col >= 0; col--) {
            int num = (grid[row][col] * pow(2, k++));
            val += num;
        }
        return val;
    }

    int matrixScore(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0)
                flipRow(grid, i);
        }

        for (int col = 1; col < n; col++) {
            if (isGreater(grid, col)) {
                flipCol(grid, col);
            }
        }

        long long ans = 0;
        for (int row = 0; row < m; row++) {
            int num = binaryToDecimal(grid, row);

            ans += num;
        }

        return ans;
    }
};