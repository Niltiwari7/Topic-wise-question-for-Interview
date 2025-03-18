class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int res = 1;
            int n = nums.size();
            int j = 0;
            int i = 0;
            int curr_and = 0;
            while (j < n) {
                while ((curr_and & nums[j]) != 0) {
                    curr_and ^= nums[i];
                    i++;
                }
    
                curr_and |= nums[j];
    
                res = max(res, j - i + 1);
                j++;
            }
            return res;
        }
    };
    