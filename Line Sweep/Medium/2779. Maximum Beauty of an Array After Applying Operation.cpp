class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int, int> mp;
        for (auto num : nums) {
            mp[num - k]++;
            mp[num + k + 1]--;
        }
        int res = 0;
        int sum = 0;
        for (auto it : mp) {
            sum += it.second;
            res = max(sum, res);
        }
        return res;
    }
};
