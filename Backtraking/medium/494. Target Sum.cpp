class Solution {
public:
    int count = 0;
    void solve(int i, vector<int>& nums, int target, int sum) {
        if (i >= nums.size()) {
            if (sum == target) {
                count++;
            }
            return;
        }
        // task1 add
        sum += nums[i];
        //explore
        solve(i + 1, nums, target, sum);
        //backtrack
        sum -= nums[i];
        // task2 = substraction
        sum -= nums[i];
        //explore
        solve(i + 1, nums, target, sum);
        //backtrack
        sum += target;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(0, nums, target, 0);
        return count;
    }
};