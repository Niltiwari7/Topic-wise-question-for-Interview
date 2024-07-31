class Solution {
public:
    int n;
    int w;
    int dp[1001][1001];
    int solve(int idx, int rem_width, vector<vector<int>>& books, int maxH) {
        if (idx >= books.size()) {
            return maxH;
        }
        if (dp[idx][rem_width] != -1) {
            return dp[idx][rem_width];
        }
        int bookW = books[idx][0];
        int bookH = books[idx][1];
        int keep = INT_MAX;
        int skip = INT_MAX;

        if (bookW <= rem_width) {
            keep = solve(idx + 1, rem_width - bookW, books, max(maxH, bookH));
        }

        skip = maxH + solve(idx + 1, w - bookW, books, bookH);

        return dp[idx][rem_width] = min(keep, skip);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        w = shelfWidth;
        memset(dp, -1, sizeof(dp));
        return solve(0, shelfWidth, books, 0);
    }
};