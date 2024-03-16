class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      int n = nums.size();
        int ans = 0;
        int count_zero = 0; // count of zeros
        int count_one = 0; // count of ones
        std::unordered_map<int,int> mp;
        mp[0] = -1; 
        
        for(int j = 0; j < n; j++) {
            if(nums[j] == 0)
                count_zero++;
            else
                count_one++;
            
            int diff = count_zero - count_one;
            
            if(mp.find(diff) != mp.end()) {
                ans = std::max(ans, j - mp[diff]);
            } else {
                mp[diff] = j;
            }
        }
        
        return ans;
    }
};