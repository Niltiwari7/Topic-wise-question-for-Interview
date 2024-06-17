class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
      int cnt = 0;
      int i = 0;
      long long maxi = 0;
      while(maxi<n){
        if(i<nums.size()&& nums[i]<=maxi+1){
            maxi+=nums[i++];
        }else{
            maxi+=maxi+1;
            cnt++;
        }
      }
      return cnt;

    }
};