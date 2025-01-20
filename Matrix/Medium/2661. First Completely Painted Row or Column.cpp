class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, pair<int, int>> mp;
        vector<int> row(m, n);
        vector<int> col(n, m);
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                mp[mat[row][col]] = {row, col};
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            auto [r, c] = mp[arr[i]];
            row[r]--;
            col[c]--;
            if (row[r] == 0 || col[c] == 0) {
                return i;
            }
        }
        return -1;
    }
};