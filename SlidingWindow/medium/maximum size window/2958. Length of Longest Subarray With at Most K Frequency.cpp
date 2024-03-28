class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0;
        unordered_map<int,int>mp;
        int ans = 0;
        for(int j = 0;j < nums.size();j++){
            mp[nums[j]]++;
            while(mp[nums[j]]>k){
                mp[nums[i]]--;
                i++;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};