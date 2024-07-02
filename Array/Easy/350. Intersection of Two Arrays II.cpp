class Solution {
public:
    vector<int> solve(vector<int> nums1, vector<int> nums2) {
        unordered_map<int, int> mp;
        for (auto it : nums2)
            mp[it]++;
        vector<int> ans;
        for (auto it : nums1) {
            if (mp.count(it)) {
                ans.push_back(it);
                mp[it]--;
                if(mp[it]==0){
                    mp.erase(it);
                }
            }
        }
        return ans;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = size(nums1);
        int n2 = size(nums2);
        vector<int> ans;
        if (n1 <= n2) {
            ans = solve(nums1, nums2);
        } else if (n1 > n2) {
            ans = solve(nums2, nums1);
        }
        return ans;
    }
};