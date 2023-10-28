class Solution {
public:
    int mod=1e9+7;
    int a=0,e=1,i=2,o=3,u=4;
    long long solve(int ch,int n,vector<vector<long long>>&dp)
    {
        if(n==0){
            return 1;
        }
        if(dp[ch][n]!=-1)return dp[ch][n];

        if(ch==a)
        {
            return dp[ch][n] = solve(e,n-1,dp)%mod;
        }else if(ch==e){
            return dp[ch][n] =solve(a,n-1,dp)%mod+solve(i,n-1,dp)%mod;
        }else if(ch==i){
            return dp[ch][n]=solve(a,n-1,dp)%mod+solve(e,n-1,dp)%mod+solve(o,n-1,dp)%mod+solve(u,n-1,dp)%mod;
        }else if(ch==o){
            return dp[ch][n]=solve(i,n-1,dp)%mod+solve(u,n-1,dp)%mod;
        }else{
            return dp[ch][n]=solve(a,n-1,dp)%mod;
        }
        return 0;
    }
    int countVowelPermutation(int n) {
        long result=0;
        vector<vector<long long>>dp(5,vector<long long>(n+1,-1));
        result+= solve(a,n-1,dp);
        result+=solve(e,n-1,dp);
        result+=solve(i,n-1,dp);
        result+=solve(o,n-1,dp);
        result+=solve(u,n-1,dp);
        return result%mod;
    }
};