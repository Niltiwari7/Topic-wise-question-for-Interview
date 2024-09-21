class Solution {
public:
    void solve(int curr, vector<int>& result, int n) {
        if (curr > n) {
            return;
        }
        result.push_back(curr);
        for (int op = 0; op <= 9; op++) {
            int ncurr = curr * 10 + op;
            if (ncurr > n) {
                return;
            }
            solve(ncurr, result, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i <= 9; i++) {
            solve(i, result, n);
        }
        return result;
    }
};