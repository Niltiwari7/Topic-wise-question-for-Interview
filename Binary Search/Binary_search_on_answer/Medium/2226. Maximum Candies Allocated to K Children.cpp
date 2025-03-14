class Solution {
    public:
        bool canPossible(vector<int>&v,long long k,long long mid){
           int n = v.size();
            long long cnt = 0;
            for(int i=0;i<n;i++){
                cnt +=1LL*(1LL*v[i]/mid);
                if(cnt>=k) return true;
            }
            return false;
        }
        int maximumCandies(vector<int>& candies, long long k) {
            long long l = 1;
            long long r = INT_MIN;
            for(auto c:candies){
                r = max(r,1LL*c);
            }
            long long res = 0;
            while(l<=r){
                long long mid = (l+r)/2;
                if(canPossible(candies,k,mid)){
                    res = mid;
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            return res;
        }
    };