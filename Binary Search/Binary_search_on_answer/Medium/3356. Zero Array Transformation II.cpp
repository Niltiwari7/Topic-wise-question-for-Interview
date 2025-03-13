class Solution {
    public:
        int n;
        int q;
    
        bool checkWithDiffTechnique(vector<int>& nums, vector<vector<int>>& queries, int k) {
            vector<int> diff(n, 0);
    
            for (int i = 0; i <= k; i++) {
                int l = queries[i][0];
                int r = queries[i][1];
                int x = queries[i][2];
    
                diff[l] += x;
                if (r + 1 < n) {
                    diff[r + 1] -= x;
                }
            }
    
            int currSum = 0;
            for (int i = 0; i < n; i++) {
                currSum += diff[i];
                if (nums[i] - currSum > 0) {
                    return false;
                }
            }
            return true;
        }
    
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            n = nums.size();
            q = queries.size();
    
            auto lambda = [](int x) { return x == 0; };
            if (all_of(begin(nums), end(nums), lambda)) {
                return 0;
            }
    
    
            int l = 0;
            int r = q - 1;
            int res = -1;
    
            while(l<=r){
                int mid = (l+r)/2;
                if(checkWithDiffTechnique(nums,queries,mid)==true){
                    res = mid;
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
    
            return res==-1?res:res+1;
        }
    };
    