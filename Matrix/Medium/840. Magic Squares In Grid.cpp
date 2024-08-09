class Solution {
public:
    bool solve(int row, int col, vector<vector<int>>& grid) {
        set<int> st;
        // Collect numbers in the 3x3 grid
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (grid[i][j] < 1 || grid[i][j] > 9) return false; // Ensure all numbers are between 1 and 9
                st.insert(grid[i][j]);
            }
        }
        // Check if all numbers from 1 to 9 are present
        if (st.size() != 9) return false;

        // Calculate sum of the first row
        int magicSum = 0;
        for (int j = col; j < col + 3; j++) {
            magicSum += grid[row][j];
        }

        // Check rows
        for (int i = row; i < row + 3; i++) {
            int rowSum = 0;
            for (int j = col; j < col + 3; j++) {
                rowSum += grid[i][j];
            }
            if (rowSum != magicSum) return false;
        }

        // Check columns
        for (int j = col; j < col + 3; j++) {
            int colSum = 0;
            for (int i = row; i < row + 3; i++) {
                colSum += grid[i][j];
            }
            if (colSum != magicSum) return false;
        }

        // Check diagonals
        int dia1 = 0, dia2 = 0;
        for (int i = 0; i < 3; i++) {
            dia1 += grid[row + i][col + i];
            dia2 += grid[row + i][col + 2 - i];
        }
        if (dia1 != magicSum || dia2 != magicSum) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m < 3 || n < 3) return 0;

        int count = 0;
        for (int i = 0; i <= m - 3; i++) {
            for (int j = 0; j <= n - 3; j++) {
                if (solve(i, j, grid)) {
                    count++;
                }
            }
        }
        return count;
    }
};
