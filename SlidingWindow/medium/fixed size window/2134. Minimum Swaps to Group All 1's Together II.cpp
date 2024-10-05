class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int windowSize = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                windowSize++;
        }
        if (windowSize == 0)
            return 0;
        nums.insert(nums.end(), nums.begin(), nums.end());
        int currOnes = 0;
        int ans = 0;
        while (j < 2 * n) {
            if (nums[j] == 1) {
                currOnes++;
            }
            while (j - i + 1 > windowSize) {
                if (nums[i] == 1) {
                    currOnes--;
                }
                i++;
            }
            if (windowSize == j - i + 1) {
                ans = max(ans, currOnes);
            }
            j++;
        }
        return windowSize - ans;
    }
};