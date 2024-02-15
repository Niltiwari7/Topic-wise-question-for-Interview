class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
       long long sum = accumulate(begin(nums),end(nums),0LL);
       sort(nums.begin(),nums.end());
       int n = nums.size()-1;
       for(int i = n;i>=0;i--){
           if(sum-nums[i]>nums[i])return sum;
           sum-=nums[i];
       } 
       return -1;
    }
};