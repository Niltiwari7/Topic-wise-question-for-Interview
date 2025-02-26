class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int maxi = INT_MIN;
            int sum = 0;
            for (auto ele : nums) {
                sum += ele;
                maxi = max(maxi, sum);
                if (sum < 0) {
                    sum = 0;
                }
            }
            int mini = INT_MAX;
            sum = 0;
            for (auto ele : nums) {
                sum += ele;
                mini = min(sum, mini);
                if (sum > 0) {
                    sum = 0;
                }
            }
            return max(abs(maxi), abs(mini));
        }
    };