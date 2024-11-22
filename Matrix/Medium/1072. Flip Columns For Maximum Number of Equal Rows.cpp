class Solution {
public:
    //Time complexity: O(m*m*n)
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
       int m = matrix.size();
       int n = matrix[0].size();
       int res = INT_MIN;
       for(auto curr:matrix){
        vector<int>inverted(n);
        for(int i = 0;i<n;i++){
            inverted[i] = curr[i]==0?1:0;
        }

        int count = 0;
        for(auto &row:matrix){
            if(row==curr || row==inverted){
                count++;
            }
        }
        res = max(res,count);
       }
       return res;
    }
};

//Efficience approach
//Time complexity - O(m*n)
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> mp;
        for (auto row : matrix) {
            string t = "";
            int firstVal = row[0];
            for (auto ch : row) {
                t += ch == firstVal ? "S" : "B";
            }
            mp[t]++;
        }
        int res = INT_MIN;
        for (auto it : mp) {
            res = max(res, it.second);
        }
        return res;
    }
};