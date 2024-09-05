class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        long long sum = accumulate(rolls.begin(),rolls.end(),0L);
        long long rem_sum = (mean*(n+m))-sum;
        if(rem_sum<n||rem_sum>6*n)return {};
        int part = rem_sum/n;
        int rem = rem_sum%n;
        vector<int>ans(n,part);
        for(int i = 0;i<rem;i++){
            ans[i]++;
        }
        return ans;
    }
};