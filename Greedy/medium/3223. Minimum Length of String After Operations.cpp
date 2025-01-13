class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        // observation 1-> string ki length agr 3 se km hui to return 0 kro
        if (n <= 2) {
            return n;
        }

        unordered_map<char, int> mp;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            res++;
            if (mp[s[i]] == 3) {
                res -= 2;
                mp[s[i]] -= 2;
            }
        }
        return res;
    }
};