class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int result = INT_MIN;
        unordered_map<int,int>mp;
        for(auto &it:nums)mp[it]++;
        for(int i = 0;i<nums.size();i++){
            if(mp.find(-nums[i])!=mp.end() && result<nums[i]){
                result = nums[i];
            }
        }
        return result==INT_MIN?-1:result;
    }
};