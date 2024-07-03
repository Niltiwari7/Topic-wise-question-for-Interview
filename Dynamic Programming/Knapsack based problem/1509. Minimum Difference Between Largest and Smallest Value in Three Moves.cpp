class Solution {
public:
    int solve(int i,int j,int k,vector<int>&nums){
        if(k<0)return INT_MAX;
        int op1 = solve(i+1,j,k-1,nums);
        int op2 = solve(i,j-1,k-1,nums);
        return min({nums[j]-nums[i],op1,op2});
    }
    int minDifference(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n = size(nums);
        if(n<=4)return 0;
        return solve(0,n-1,3,nums);
    }
};