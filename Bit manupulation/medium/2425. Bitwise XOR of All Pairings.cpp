class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int _xor1 = 0, _xor2 = 0;
        if (nums2.size() % 2 != 0) {
            for (auto& ele : nums1) {
                _xor1 ^= ele;
            }
        }

        if (nums1.size() % 2 != 0) {
            for (auto& ele : nums2) {
                _xor2 ^= ele;
            }
        }
        return _xor1 ^ _xor2;
    }
};