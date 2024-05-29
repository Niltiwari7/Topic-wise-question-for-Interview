class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int start = 0, end = 0, sum = 0;
        int ans = 0;
        while (end < s.size()) {
            sum += abs(s[end] - t[end]);
            while (sum > maxCost) {
                sum -= abs(s[start] - t[start]);
                start += 1;
            }
            ans = max(ans, end - start+1);
            end++;
        }
        return ans;
    }
};