class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(int i =0;i<strs.size();i++){
            string temp = strs[i];
            sort(begin(strs[i]),end(strs[i]));
            mp[strs[i]].push_back(temp);
        }
        vector<vector<string>>res;
        for(auto it:mp) res.push_back(it.second);

        return res;
    }
};