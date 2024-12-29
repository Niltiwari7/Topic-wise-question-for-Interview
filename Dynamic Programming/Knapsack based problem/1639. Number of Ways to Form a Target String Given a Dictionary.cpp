class Solution {
public:
    int M; // target length
    int K; // each word length
    int dp[1001][1001];
    int MOD = 1e9 + 7;
    int solve(int i, int j, vector<vector<long long>>& freq, string& target) {
        if (i == M) {
            return 1;
        }
        if (j == K) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int not_taken = solve(i, j + 1, freq, target) % MOD;
        int taken = 0;
        if (freq[target[i] - 'a'][j] > 0) {
            taken =
                (freq[target[i] - 'a'][j] * solve(i + 1, j + 1, freq, target)) %
                MOD;
        }

        return dp[i][j] = (taken + not_taken) % MOD;
    }
    int numWays(vector<string>& words, string target) {

        M = target.size();
        K = words[0].size();
        memset(dp, -1, sizeof(dp));
        vector<vector<long long>> freq(26, vector<long long>(K, 0));
        for (int col = 0; col < K; col++) {
            for (auto& word : words) {
                char ch = word[col];
                freq[ch - 'a'][col]++;
            }
        }
        return solve(0, 0, freq, target);
    }
};