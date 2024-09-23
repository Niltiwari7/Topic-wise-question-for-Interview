class Solution {
public:
    int dp[51];
    int solve(int idx, string s, unordered_set<string>& st) {
        if (idx >= s.size()) {
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        string currStr = "";
        int res = INT_MAX;
        for (int i = idx; i < s.size(); i++) {
            currStr.push_back(s[i]);
            int totExtra =
                (st.count(currStr) ? 0 : currStr.size()) + solve(i + 1, s, st);
            res = min(res, totExtra);
        }
        return dp[idx] = res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        memset(dp,-1,sizeof(dp));
        int ans = solve(0, s, st);
        return ans;
    }
};