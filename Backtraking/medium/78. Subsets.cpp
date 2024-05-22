class Solution {
public:
    vector<vector<int>> result;
    void solve(int i, vector<int>& nums, vector<int> ds) {
        if (i >= nums.size()) {
            result.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        solve(i + 1, nums, ds);
        ds.pop_back();
        solve(i + 1, nums, ds);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        solve(0, nums, ds);
        sort(result.begin(), result.end());
        return result;
    }
};