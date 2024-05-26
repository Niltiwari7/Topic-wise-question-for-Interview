class Solution {
public:
    vector<string> result;
    void solve(int i, string s, unordered_map<string, int>& mp, string curr) {
        if (i == s.size()) {
            result.push_back(curr.substr(0, curr.size() - 1));
            return;
        }
        string temp = "";
        string anothertemp = curr;
        for (int j = i; j < s.size(); j++) {
            temp += s[j];
            if (mp[temp]) {
                curr += temp + " ";
                solve(j + 1, s, mp, curr);
                curr = anothertemp;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> mp;
        for (auto& word : wordDict)
            mp[word]++;
        solve(0, s, mp, "");
        return result;
    }
};