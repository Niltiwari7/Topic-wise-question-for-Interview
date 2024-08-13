class Solution {
public:
    vector<vector<int>> result;
    void solve(int i, vector<int>& nums, int target, vector<int>& ds) {
        if (target == 0) {
            result.push_back(ds);
            return;
        }
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1])
                continue;
            if (nums[j] > target)
                break;
            ds.push_back(nums[j]);
            solve(j + 1, nums, target - nums[j], ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, ds);
        return result;
    }
};