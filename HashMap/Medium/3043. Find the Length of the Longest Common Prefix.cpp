class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int>mp;
        for(auto ele:arr1){
            string s = to_string(ele);
            for(int i = 1;i<=s.size();i++){
                mp[s.substr(0,i)]++;
            }
        }

        int res = 0;
        for(auto ele:arr2){
            string s = to_string(ele);
            for(int i = 1;i<=s.size();i++){
                if(mp.find(s.substr(0,i))!=mp.end()){
                    res = max(res,i);
                }
            }
        }
        return res;
    }
};