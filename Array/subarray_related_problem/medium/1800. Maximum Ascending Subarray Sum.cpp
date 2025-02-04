// Brtue force
// Time Complexity - O(n^2)
// Space Complexity - O(1)
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            int sum = nums[i];
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] > nums[j - 1]) {
                   sum+=nums[j];
                } else {
                    res = max(sum,res);
                    sum = 0;
                }
            }
            res = max(res, sum);
        }
        return res;
    }
};


// Better approach

// Time Complexity - O(n)
// Space Complexity - O(1)
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0];
        int n = nums.size();
        int res = 0;
        res = max(res, sum);
        if (n == 1) {
            return nums[0];
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                sum += nums[i];
            } else {
                sum = nums[i];
            }
            res = max(res, sum);
        }
        return res;
    }
};