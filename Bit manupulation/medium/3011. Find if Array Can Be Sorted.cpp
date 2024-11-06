class Solution {
public:
    bool check(int num1, int num2) {
        int cnt1 = __builtin_popcount(num1);
        int cnt2 = __builtin_popcount(num2);
        return cnt1 == cnt2;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((j + 1 < n) && (nums[j] > nums[j + 1]) &&
                    check(nums[j], nums[j + 1])) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        if (nums[0] > nums[n - 1])
            return false;
        return true;
    }
};