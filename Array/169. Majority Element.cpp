class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(auto it:nums)mp[it]++;
        for(auto [ele,freq]:mp){
            if(freq>n/2)return ele;
        }
        return -1;
    }
};