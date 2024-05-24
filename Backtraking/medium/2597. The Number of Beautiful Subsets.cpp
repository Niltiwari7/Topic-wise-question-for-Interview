class Solution {
public:
    int K;
    int result = 0;
    void solve(int i, vector<int>& nums, unordered_map<int, int>& mp) {
        if (i >= nums.size()) {
            result++;
            return;
        }
        solve(i + 1, nums, mp);
        if (!mp[nums[i] - K] && !mp[nums[i] + K]) {
            mp[nums[i]]++;
            solve(i + 1, nums, mp);
            mp[nums[i]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        K = k;
        unordered_map<int, int> mp;
        solve(0, nums, mp);
        return result - 1;
    }
};