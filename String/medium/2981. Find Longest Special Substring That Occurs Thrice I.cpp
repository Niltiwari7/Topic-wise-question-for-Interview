// Time Complexity - O(n^2)
// Space Complexity - O(n^2)
class Solution {
public:
    bool isSpl(string s){
        unordered_set<char>st(s.begin(),s.end());
        return st.size()==1;
    }
    int maximumLength(string s) {
        unordered_map<string, int> mp;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 1; j <= s.size() - i; j++) {
                string t = s.substr(i, j);
                mp[t]++;
            }
        }
        int res = -1;
        for (auto it : mp) {
            if (it.second >= 3) {
                int sz = it.first.size();    
                if (res < sz && isSpl(it.first)) {
                    res = it.first.size();
                }
            }
        }
        return res;
    }
};