class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto &q:queries){
            int x = q[0];
            int y = q[1];
            int _xor = 0;
            for(int i = x;i<=y;i++){
                _xor^=arr[i];
            }
            ans.push_back(_xor);
        }
        return ans;
    }
};