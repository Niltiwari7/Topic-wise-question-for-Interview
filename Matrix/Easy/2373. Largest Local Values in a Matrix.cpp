class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();

      vector<vector<int>>result;
      for(int i = 0 ;i<=m-3;i++){
        vector<int>temp;
        for(int j = 0;j<=n-3;j++){
            int currMax = INT_MIN;
            for(int k=i;k<i+3;k++){
                for(int l=j;l<j+3;l++){
                    currMax = max(currMax,grid[k][l]);
                }
            }
            temp.push_back(currMax);
        }
        result.push_back(temp);
      }   
      return result;
    }
};