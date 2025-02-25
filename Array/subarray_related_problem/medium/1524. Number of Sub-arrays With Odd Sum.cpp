class Solution {
    public:
        int MOD = 1e9 + 7;
        
        int numOfSubarrays(vector<int>& arr) {
            int n = arr.size();
            int res = 0, sum = 0;
            unordered_map<int, int> mp;
            mp[0] = 1; 
            
            for(int i = 0; i < n; i++) {
                sum += arr[i];
                int rem = sum % 2;
                if (rem < 0) rem += 2; 
             
                if (rem == 1) res = (res + mp[0]) % MOD;
                else res = (res + mp[1]) % MOD;
    
               
                mp[rem]++;
            }
            
            return res;
        }
    };
    