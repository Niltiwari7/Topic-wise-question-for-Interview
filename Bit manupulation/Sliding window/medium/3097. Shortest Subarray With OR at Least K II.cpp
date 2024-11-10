class Solution {
public:
    void addNumToWindow(int num, vector<int>& bitset) {
        for (int i = 0; i < 32; i++) {
            if ((num >> i) & 1) {
                bitset[i]++;
            }
        }
    }

    void removeNumFromWindow(int num, vector<int>& bitset) {
        for (int i = 0; i < 32; i++) {
            if ((num >> i) & 1) {
                bitset[i]--;
            }
        }
    }
    int getDecimalNumber(vector<int>& bitset) {
        int num = 0;

        for (int i = 31; i >= 0; i--) {
            if (bitset[i] > 0) {
                num |= (1 << i);
            }
        }
        return num;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bitSet(32, 0);
        int i = 0;
        int j = 0;
        int result = INT_MAX;

        while (j < n) {
            addNumToWindow(nums[j], bitSet);
            while (i <= j && getDecimalNumber(bitSet) >= k) {
                result = min(result, j - i + 1);
                removeNumFromWindow(nums[i], bitSet);
                i++;
            }
            j++;
        }
        return result == INT_MAX ? -1 : result;
    }
};