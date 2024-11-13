class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int low =
                lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) -
                begin(nums);
            int high =
                upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) -
                begin(nums);
            count += 1LL * (high - low);
        }
        return count;
    }
};