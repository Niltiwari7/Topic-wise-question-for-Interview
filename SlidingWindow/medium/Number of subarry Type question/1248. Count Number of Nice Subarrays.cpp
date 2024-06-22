class Solution {
public:
    int solve(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int count = 0;
        int res = 0;
        int n = nums.size();
        while (j < n) {
            if (nums[j] % 2 == 1)
                count++;

            while (count > k) {
                if (nums[i] % 2 == 1) {
                    count--;
                }
                i++;
            }
            res += (j - i + 1);
            j++;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};