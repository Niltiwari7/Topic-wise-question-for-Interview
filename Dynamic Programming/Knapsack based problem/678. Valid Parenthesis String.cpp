class Solution {
public:
    bool solve(int i,int openBracket,string s,vector<vector<int>>&dp){
        if(i==s.size())return openBracket==0;
        if(dp[i][openBracket]!=-1)return dp[i][openBracket];
        bool ans = false;
        if(s[i]=='*'){
            ans|=solve(i+1,openBracket+1,s,dp);
            if(openBracket){
                ans|=solve(i+1,openBracket-1,s,dp);
            }
            ans|=solve(i+1,openBracket,s,dp);
        }else{
            if(s[i]=='('){
                ans |= solve(i+1,openBracket+1,s,dp);
            }else{
                if(openBracket) ans |= solve(i+1,openBracket-1,s,dp);
            }
        }
        return dp[i][openBracket] = ans;
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,0,s,dp);
    }
};