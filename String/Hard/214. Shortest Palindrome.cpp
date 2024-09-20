#include <cstring> 

class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s;
        int n = s.size();
        reverse(t.begin(), t.end());
        if (s == t)
            return s;
        for (int i = 0; i < n; i++) {
            if (memcmp(s.c_str(), t.c_str() + i, n - i) == 0) {
                return t.substr(0, i) + s;
            }
        }

        return s;
    }
};
