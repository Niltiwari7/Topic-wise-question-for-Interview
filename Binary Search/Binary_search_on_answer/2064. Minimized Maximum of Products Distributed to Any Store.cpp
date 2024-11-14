class Solution {
public:
    bool isPossible(const vector<int>& quantities, int mid, int n) {
        int requiredShops = 0;
        for (int quantity : quantities) {
            requiredShops += (quantity) / mid;
            requiredShops += ((quantity % mid == 0) ? 0 : 1);
            if (requiredShops > n) {
                return false;
            }
        }
        return requiredShops <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());
        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(quantities, mid, n)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
