class Solution {
public:
    vector<vector<int>> result;
    void solve(int i, vector<int>& nums, vector<int> ds) {
        if (i == nums.size()) {
            result.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        solve(i + 1, nums, ds);
        ds.pop_back();
        solve(i + 1, nums, ds);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int> ds;
        solve(0, nums, ds);
        int sum = 0;

        for (auto& vec : result) {
            int xor_val = 0;
            for (auto& ele : vec) {
                xor_val ^= ele;
            }
            sum += xor_val;
        }
        return sum;
    }
};