class Solution {
    public:
        
        long long nCr(int n, int r) {
            if (r > n) return 0;
            if (r == 0 || n == r) return 1;
            double res = 0;
            for (int i = 0; i < r; i++) {
                res += log(n - i) - log(i + 1);
            }
            return (long long)round(exp(res));
        }
    
    
        long long countBadPairs(vector<int>& nums) {
            long long res = 0;
            unordered_map<int, int> mp;
            long long count = 0;
    
            // Count occurrences of i - nums[i]
            for (int i = 0; i < nums.size(); i++) {
                mp[i - nums[i]]++;
            }
    
            // Calculate the number of good pairs
            for (auto ele : mp) {
                if (ele.second > 1) {
                    count += 1LL*((1LL*ele.second * (1LL*ele.second - 1)) / 2);
                }
            }
    
            // Total number of pairs (n choose 2)
            int n = nums.size();
            long long tot = nCr(n, 2);
    
            // Bad pairs are total pairs minus good pairs
            res = tot - count;
    
            return res;
        }
    };
    
    
    