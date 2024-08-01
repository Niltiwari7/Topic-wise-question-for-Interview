class Solution {
public:
   int solve(int row,int col,vector<vector<int>>&v,int m,int n,int k){
    if(row<0 || col<0||row>=m||col>=n||v[row][col]==2||k<0){
        return INT_MAX;
    }
    if(row==m-1 && col==n-1){
        return 0;
    }
    
    int temp = v[row][col];
    v[row][col] = 2;
    int result = INT_MAX;
    if(temp==1){
        int up = solve(row-1,col,v,m,n,k-1);
        int down = solve(row+1,col,v,m,n,k-1);
        int left = solve(row,col-1,v,m,n,k-1);
        int right = solve(row,col+1,v,m,n,k-1);
         if (up != INT_MAX || down != INT_MAX || left != INT_MAX || right != INT_MAX) {
            result = 1 + min({up, down, left, right});
        }
    }else{
        int up = solve(row-1,col,v,m,n,k);
        int down = solve(row+1,col,v,m,n,k);
        int left = solve(row,col+1,v,m,n,k);
        int right = solve(row,col-1,v,m,n,k);
       if (up != INT_MAX || down != INT_MAX || left != INT_MAX || right != INT_MAX) {
            result = 1 + min({up, down, left, right});
        }
    }
    v[row][col] = temp;
    return result;
    
}
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int result = solve(0, 0, grid,m,n, k);
        return result == INT_MAX ? -1 : result;
    }
};
