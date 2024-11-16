class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n - k + 1, -1);
        if (n == 1) {
            return nums;
        }
        if (k == n) {
            return {*max_element(nums.begin(), nums.end())};
        }
        for (int i = 0; i <= n - k; i++) {
            int count = 1;
            int maxi = nums[i];
            for (int l = 1; l < k; l++) {
                if (nums[l + i - 1] + 1 == nums[i + l]) {
                    count++;
                }
            }
            if (count == k) {
                result[i] = nums[i + k - 1];
            }
        }
        return result;
    }
};