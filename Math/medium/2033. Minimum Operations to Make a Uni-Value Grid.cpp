class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> nums;
            for (auto ele : grid) {
                for (int e : ele) {
                    nums.push_back(e);
                }
            }
    
            int res = 0;
            sort(begin(nums),end(nums));
            int target = nums[nums.size() / 2];
            for (int num : nums) {
                int diff = abs(target - num);
                if (diff % x != 0)
                    return -1;
                res += (diff / x);
            }
            return res;
        }
    };
    