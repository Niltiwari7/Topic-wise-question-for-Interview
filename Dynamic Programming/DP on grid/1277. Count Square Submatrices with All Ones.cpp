class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp ){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int right = solve(i,j+1,grid,dp);
        int left = solve(i+1,j,grid,dp);
        int bottom = solve(i+1,j+1,grid,dp);
        return dp[i][j]= 1+min({right,left,bottom});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j]==1){
                    count+=solve(i,j,matrix,dp);
                }
            }
        }
        return count;
    }
};