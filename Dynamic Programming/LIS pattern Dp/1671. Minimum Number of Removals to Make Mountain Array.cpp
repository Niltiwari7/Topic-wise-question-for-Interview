class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0;
        vector<int> dpLeft(n, 1);
        vector<int> dpRight(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dpLeft[i] = max(dpLeft[i], 1 + dpLeft[j]);
                }
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    dpRight[i] = max(dpRight[i], dpRight[j] + 1);
                }
            }
        }

        int maxi = 0;
        for (int i = 0; i < n; i++) {
             if(dpLeft[i]==1 || dpRight[i]==1)continue;
            int ans = dpLeft[i] + dpRight[i] - 1;
            // cout<<ans<<" ";
            maxi = max(maxi, ans);
        }
        return n - maxi;
    }
};