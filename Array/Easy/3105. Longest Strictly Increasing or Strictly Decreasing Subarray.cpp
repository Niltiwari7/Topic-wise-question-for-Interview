class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 1;
        }
        int res = 1;
        for (int i = 0; i < nums.size(); i++) {
            int cntInc = 1;
            int cntDec = 1;
            for (int j = i; j < nums.size()-1; j++) {
                if (nums[j] < nums[j + 1]) {
                    cntInc++;
                    cntDec=1;
                } else if (nums[j] > nums[j + 1]) {
                    cntDec++;
                    cntInc=1;
                } else {
                    break;
                }
                res  = max({res,cntInc,cntDec});
            }
        }
        return res;
    }
};