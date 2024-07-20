class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        vector<vector<int>>mat(m,vector<int>(n,0));
        int i = 0;
        int j = 0;
        while(i<m && j<n){
            mat[i][j] = min(rowSum[i],colSum[j]);
            if(colSum[j]>rowSum[i]){
                colSum[j]-=rowSum[i];
                i++;
            }else{
                rowSum[i]-=colSum[j];
                j++;
            }
        }
       return mat;
    }
};