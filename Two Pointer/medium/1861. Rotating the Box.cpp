class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>>grid(n,vector<char>(m,'.'));
        for(int i = 0;i<n;i++){
            for(int j = m-1;j>=0;j--){
               grid[i][m-1-j] = box[j][i];
            }
        }
        for(int i = 0;i<m;i++){
          int start = n-1;
          for(int j = start;j>=0;j--){
            if(grid[j][i]=='*'){
                start  = j-1;
            }else if(grid[j][i]=='#'){
                grid[j][i] = '.';
                grid[start][i] = '#';
                start--;
            }
          }
        }
        return grid;
    }
};