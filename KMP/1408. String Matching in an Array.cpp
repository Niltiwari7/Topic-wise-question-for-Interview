class Solution {
public:
    bool isSubstring(string& a, string& b) {
        if (b.find(a) != string::npos) {
            return true;
        }
        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (words[i] == words[j])
                    continue;
                if (isSubstring(words[i], words[j])) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};