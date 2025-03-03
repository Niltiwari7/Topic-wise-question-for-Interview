class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int> ans;
            for (auto num : nums) {
                if (num < pivot) {
                    ans.push_back(num);
                }
            }
            int c = count(nums.begin(), nums.end(), pivot);
            while (c--) {
                ans.push_back(pivot);
            }
    
            for (auto num : nums) {
                if (pivot < num) {
                    ans.push_back(num);
                }
            }
            return ans;
        }
    };