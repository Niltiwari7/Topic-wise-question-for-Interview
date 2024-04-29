class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for(auto num:nums)
        {
            k^=num;
        }
        return __builtin_popcount(k);
    }
};