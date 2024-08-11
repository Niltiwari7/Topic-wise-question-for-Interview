class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&vis){
        if(row<0 || col<0||row>=grid.size()||col>=grid[0].size()||grid[row][col]==0||vis[row][col]==1){
            return;
        }

        vis[row][col] = 1;
        dfs(row+1,col,grid,vis);
        dfs(row,col+1,grid,vis);
        dfs(row-1,col,grid,vis);
        dfs(row,col-1,grid,vis);
    }
    int count(vector<vector<int>>&grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));
        int count = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    dfs(i,j,grid,vis);
                    count++;
                }
            }
        }
        return count;
    }
    int minDays(vector<vector<int>>& grid) {
        if(count(grid)>1 || count(grid)==0){
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        int landCount = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1){
                    landCount++;
                }
            }
        }
        if(landCount==1){
            return 1;
        }
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    int island = count(grid);
                    if(island>1){
                        return 1;
                    }
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};