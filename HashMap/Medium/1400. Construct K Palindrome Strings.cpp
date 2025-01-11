// Time Complexity - O(n)
// space Complexity - O(n)
class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if (n == k)
            return true;
        if (n < k)
            return false;
        unordered_map<char, int> mp;
        for (auto ch : s) {
            mp[ch]++;
        }
        int odd_count = 0;
        for (auto [ele, freq] : mp) {
            if (freq % 2 == 1) {
                odd_count++;
            }
        }
        if (odd_count > k) {
            return false;
        }
        return true;
    }
};