class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;
        long long res = INT_MIN;
        long long sum = 0;
        while (j < nums.size()) {
            mp[nums[j]]++;
            sum += nums[j];
            while (j - i + 1 > k) {
                mp[nums[i]]--;
                sum -= nums[i];
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            if (j - i + 1 == k) {
                if (mp.size() == k) {
                    res = max(sum, res);
                }
            }

            j++;
        }
        return res == INT_MIN ? 0 : res;
    }
};