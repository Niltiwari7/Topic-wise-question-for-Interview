class Solution {
public:
    bool check(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> v, ans;
        v.push_back(0);

        for (auto w : words) {
            v.push_back(v.back() + (check(w[0]) && check(w.back())));
        }
        for (auto q : queries) {
            ans.push_back(v[q[1] + 1] - v[q[0]]);
        }
        return ans;
    }
};