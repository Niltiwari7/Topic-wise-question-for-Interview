class Solution {
public:
     typedef long long ll;
    int isPossible(int mid, int k, int m, vector<int>& b) {
        ll count = 0;
        ll bouquets = 0;
        for (int i = 0; i < b.size(); i++) {
            if (mid >= b[i]) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return bouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if (1LL*m * k > bloomDay.size())
            return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        ll ans = -1;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (isPossible(mid, k, m, bloomDay) >= m) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
