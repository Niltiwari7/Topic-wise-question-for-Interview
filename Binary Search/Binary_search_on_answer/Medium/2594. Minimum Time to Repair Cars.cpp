class Solution {
    public:
        typedef long long ll;
        bool isPossible(vector<int>& ranks, int car, ll mid) {
            ll count = 0;
            for (int i = 0; i < ranks.size(); i++) {
                count += sqrt(mid/(1LL*ranks[i]));
            }
            return count >= car;
        }
        long long repairCars(vector<int>& ranks, int cars) {
            ll low = 1;
            ll high = *max_element(begin(ranks), end(ranks)) * pow(cars, 2);
           
            ll res = -1;
            while (low <= high) {
                ll mid = (low + (high - low) / 2);
    
                if (isPossible(ranks, cars, mid)) {
                    res = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return res;
        }
    };
    
    /*
     car mechanice =0 - 4*1*1 = 4
                    1 - 2*1*1 = 2
                    2 - 3*1*1 = 3
                    4 - 1*1*1 = 1
                    tot       = 10 minute
                    by observation that we find out the we can do binary search on
     minutes we need to find out what will be the range minute mean what will the
     low   = 1 (a mechanic can repair one car) high  =
    */