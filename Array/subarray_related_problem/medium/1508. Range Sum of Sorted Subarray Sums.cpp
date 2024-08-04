class Solution {
public:
    int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long ans = 0;
        vector<long long> subarraySum;
        for (int i = 0; i < nums.size(); i++) {
            long long sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                subarraySum.push_back(sum);
            }
        }

        sort(subarraySum.begin(), subarraySum.end());

        for (int i = left - 1; i < right; i++) {
            ans = (ans + subarraySum[i]) % mod;
        }
        return ans;
    }
};