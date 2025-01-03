class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<long long>pref(n,0);
        vector<long long>suff(n,0);
        pref[0]=nums[0];
        for(int i = 1;i<n;i++){
            pref[i]=nums[i]+pref[i-1];
        }
        suff[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            suff[i]=suff[i+1]+nums[i];
        }  
        for(int i = 0;i<n-1;i++){
            if(pref[i]>=suff[i+1])res++;
        }
        return res;
    }
};