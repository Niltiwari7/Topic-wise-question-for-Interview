class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int _xor = pow(2,maximumBit)-1;
        int n = nums.size();
        vector<int>prefix(n,0);
        prefix[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            prefix[i] = prefix[i-1]^nums[i];
        }
        vector<int>ans(n,0);
        int k = 0;
        for(int i = n-1;i>=0;i--){
            ans[k++] = _xor^prefix[i];
        }
        return ans;
    }
};