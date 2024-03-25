class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>result;
        for(auto &it:nums){
            if(mp.find(it)!=mp.end()){
                result.push_back(it);
            }else{
                mp[it]++;
            }
        }
        return result;
    }
};