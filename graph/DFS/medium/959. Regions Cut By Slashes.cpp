class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&mat,vector<vector<int>>&vis){
        if((row<0) || (col<0) || (row>=mat.size()) || (col>=mat[0].size()) || (mat[row][col]==1) || vis[row][col]==1){
            return;
        }
        vis[row][col]=1;
        dfs(row+1,col,mat,vis);
        dfs(row,col+1,mat,vis);
        dfs(row-1,col,mat,vis);
        dfs(row,col-1,mat,vis);
    }
    int regionsBySlashes(vector<string>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>>mat(row*3,vector<int>(col*3,0));

        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(grid[i][j]=='/'){
                    mat[i*3][j*3+2] = 1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3+2][j*3] = 1;
                }else if(grid[i][j]=='\\'){
                    mat[i*3][j*3]=1;
                    mat[i*3+1][j*3+1]=1;
                    mat[i*3+2][j*3+2]=1;
                }
            }
        }
        int count = 0;
        vector<vector<int>>vis(row*3,vector<int>(col*3,0));
        for(int i = 0;i<mat.size();i++){
            for(int j = 0;j<mat[0].size();j++)
            {
                if(!vis[i][j] && mat[i][j]==0){
                    dfs(i,j,mat,vis);
                    count++;
                }
            }
        }
        return count;
    }
};