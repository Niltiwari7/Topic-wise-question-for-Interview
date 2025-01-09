class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int sz = pref.size();
        int res = 0;
        for (auto w : words) {
            string temp = w.substr(0, sz);
            if (temp == pref) {
                res++;
            }
        }
        return res;
    }
};