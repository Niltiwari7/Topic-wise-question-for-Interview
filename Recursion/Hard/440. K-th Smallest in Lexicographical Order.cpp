class Solution {
public:
    long long count(long long curr, long long next, long long n) {
        long long c = 0;
        while (curr <= n) {
            c += (next - curr);
            curr *= 10;
            next *= 10;
            next = min(next, n + 1);
        }
        return c;
    }
    int findKthNumber(int n, int k) {
        long long curr = 1;
        long long next = 2;
        k -= 1;
        // int res  = 0;
        while (k > 0) {
            long long countNum = count(curr, curr + 1, n);
            if (countNum <= k) {
                curr++;
                k -= countNum;
            } else {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};