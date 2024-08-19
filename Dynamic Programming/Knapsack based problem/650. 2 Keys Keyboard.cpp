class Solution {
public:
    int dp[1001][1001];
    int solve(int n, int ch, int clip) {
        
        if (ch > n) {
            return INT_MAX; 
        }
        if (ch == n) {
            return 0; 
        }
        if(dp[ch][clip]!=-1){
            return dp[ch][clip];
        }
        
        int copyPaste = INT_MAX;
        int paste = INT_MAX;

        if (clip != ch) { 
            int result = solve(n, ch + ch, ch);
            if (result != INT_MAX) {  
                copyPaste = 2 + result;
            }
        }

        
        if (clip > 0) { 
            int result = solve(n, ch + clip, clip);
            if (result != INT_MAX) {  
                paste = 1 + result;
            }
        }

        return dp[ch][clip] = min(copyPaste, paste);
    }

    int minSteps(int n) {
        memset(dp,-1,sizeof(dp));
        int ch = 1; 
        return solve(n, ch, 0); 
    }
};
