class Solution {
public:
    int dp[1001][1001];
    int solve(int i ,int j,vector<vector<int>>&grid){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int res = 0;
        if(i>0 && j+1<grid[0].size() && (grid[i][j] < grid[i-1][j+1])){
            res = max(res,1+solve(i-1,j+1,grid));
        }
        if(j+1<grid[0].size() && (grid[i][j]<grid[i][j+1])){
            res = max(res,1+solve(i,j+1,grid));
        }
        if(i+1<grid.size() && j+1<grid[0].size() && (grid[i][j]<grid[i+1][j+1])){
            res = max(res,1+solve(i+1,j+1,grid));
        }
        return dp[i][j] = res;
    }
    int maxMoves(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       int res = 0;
       memset(dp,-1,sizeof(dp));
       for(int i = 0;i<m;i++){
        res = max(res,solve(i,0,grid));
       } 
       return res;
    }
};