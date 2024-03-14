class Solution {
public:
    int solve(vector<int>&nums,int goal){
        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = 0;
        if(goal<0)return 0;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>goal){
             sum-=nums[i++];
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return solve(nums,goal)-solve(nums,goal-1); 
    }
};