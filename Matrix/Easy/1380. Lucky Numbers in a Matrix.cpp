class Solution {
public:
    bool isAns(int row, int col, vector<vector<int>>& matrix, int m, int n) {
        int lol = matrix[row][col];

        for (int i = 0; i < m; i++) {
            if (matrix[i][col] > lol) {
                return false;
            }
        }

        for (int i = 0; i < n; i++) {
            if (matrix[row][i] < lol) {
                return false;
            }
        }
        return true;
    }
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isAns(i, j, matrix, m, n)) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};