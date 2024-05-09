class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        int n = happiness.size()-1;
        sort(happiness.begin(),happiness.end());
        long long cnt = 0;
        while(n>=0 && k>0){
            if(happiness[n]-cnt>=0){
                ans+=happiness[n]-cnt;
            }else{
                break;
            }
            n--;
            k--;
            cnt++;
        }
        return ans;
    }
};