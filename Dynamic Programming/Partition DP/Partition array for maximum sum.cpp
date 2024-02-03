class Solution {
public:
    int solve(int i,vector<int>&arr,int k,vector<int>&dp){
        if(i==arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        for(int j=i;j < min(i+k,static_cast<int>(arr.size()));j++){
            len++;
            maxi = max(maxi,arr[j]);
            int sum = len*maxi+solve(j+1,arr,k,dp);
            maxAns = max(maxAns,sum);
        }
        return dp[i] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,-1);
        return solve(0,arr,k,dp);
    }
};