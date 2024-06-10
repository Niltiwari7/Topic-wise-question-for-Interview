class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int,int>mp;
        mp[0] = 1;
        int result  = 0;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
            int rem = sum%k;
            if(rem<0){
                rem+=k;
            }
            if(mp.count(rem)){
                result+=mp[rem];
                mp[rem]++;
            }else{
                mp[rem]++;
            }
        }
        return result;
    }
};