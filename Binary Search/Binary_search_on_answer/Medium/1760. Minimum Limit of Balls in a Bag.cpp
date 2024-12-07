// Time Complexity - O(nlog(max(nums)))
// Space Complexity - O(1)
class Solution {
public:
    bool isPossible(int mid, vector<int>& nums, int mOps) {
        int tot = 0;
        for (int num : nums) {
            // If number is divisible then number of operation = (num/mid-1)
            // else operation = (num/mid)
            tot += (num % mid == 0) ? (num / mid - 1) : num / mid;
            if (tot > mOps) {
                return false;
            }
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(mid, nums, maxOperations)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
