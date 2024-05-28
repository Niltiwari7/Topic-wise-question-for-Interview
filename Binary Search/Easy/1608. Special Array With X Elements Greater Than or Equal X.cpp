class Solution {
public:
    int canAns(int x, vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (x <= nums[i]) {
                count++;
            }
        }
        if (count == x) {
            return 1;
        } else if (count > x) {
            return 2;
        } else {
            return 3;
        }
    }
    int specialArray(vector<int>& nums) {

        int low = 0;
        int high = nums.size();

        while (low <= high) {
            int mid = (high + low) / 2;
            int val = canAns(mid, nums);
            if (val == 1) {
                return mid;
            } else if (val == 2) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};