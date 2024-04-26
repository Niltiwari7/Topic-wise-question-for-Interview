class Solution {
public:
    int dp[201][201]; 
    int solve(int col,int row,vector<vector<int>>&grid){
        if(row==grid.size()-1){
            return grid[row][col];
        }
        if(dp[row][col]!=-1)return dp[row][col];
        int ans = INT_MAX;
        for(int nextcol = 0;nextcol<grid.size();nextcol++){
            if(nextcol!=col){
                ans = min(ans,solve(nextcol,row+1,grid));
            }
        }
        return dp[row][col] = grid[row][col]+ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int result = INT_MAX;
        memset(dp,-1,sizeof(dp));
        for(int col = 0;col<n;col++){
            result = min(result,solve(col,0,grid));
        }
        return result;
    }
};