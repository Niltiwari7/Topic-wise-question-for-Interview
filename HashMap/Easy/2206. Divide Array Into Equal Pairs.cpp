class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            int n = nums.size();
            unordered_map<int, int> mp;
            for (auto ele : nums) {
                mp[ele]++;
            }
            for (auto it : mp) {
                if (it.second % 2) {
                    return false;
                }
            }
            return true;
        }
    };