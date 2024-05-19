class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        long long ans = 0;

        int count = 0;
        int minimum_val = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < (nums[i] ^ k)) {
                count++;
                ans += (nums[i] ^ k);
            } else {
                ans += nums[i];
            }
            minimum_val = min<long long>(1LL * minimum_val,
                                         1LL * abs(nums[i] - (nums[i] ^ k)));
        }
        if (count % 2 == 1) {
            return ans - minimum_val;
        }
        return ans;
    }
};