// Time Complexity - O(n)
// Space Complexity - O(n)
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        vector<int> ans(1, 0);
        for (int i = 1; i < nums.size(); i++) {
            ans.push_back(ans.back() + (nums[i] % 2 == nums[i - 1] % 2));
        }
        vector<bool> result;
        for (auto q : queries) {
            int s = q[0];
            int e = q[1];
            if (ans[s] - ans[e] == 0) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};