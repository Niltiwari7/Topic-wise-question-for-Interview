class Solution {
public:
    int atmost(vector<int>&nums,int k){
        unordered_map<int,int>mp;

        long long count = 0;
        int i = 0;
        for(int j = 0;j<size(nums);j++){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            count+=(j-i+1);
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};