class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,int>mp;
        for(auto &v:intervals){
            mp[v[0]]++;
            mp[v[1]+1]--;
        }
        int res = 0;
        int curr=0;
        for(auto &it:mp){
            res = max(res,curr+=it.second);
        }
        return res;
    }
};