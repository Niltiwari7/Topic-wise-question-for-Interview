class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int>dp(26,0);
        int result = 0;
        for(int i = 0;i<n;i++){
            int curr = s[i]-'a';
            int left = max(0,curr-k);
            int right =min(25,curr+k);
            int longest = 0;
            for(int j = left;j<=right;j++){
                longest = max(longest,dp[j]);
            }
            dp[curr] = max(dp[curr],longest+1);
            result = max(result,dp[curr]);

        }
        return result;
    }
};