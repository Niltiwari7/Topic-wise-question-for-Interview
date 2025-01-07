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


// Using KMP algorithm

class Solution {
public:
    vector<int> LPS(string s) {
        int length = 0;
        int n = s.size();
        int i = 1;
        vector<int> lps(n, 0);
        while (i < n) {
            if (s[i] == s[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    bool searchPattern(string& txt, string& pattern) {
        int n = txt.size();
        int m = pattern.size();

        if (m == 0) {
            return true;
        }

        vector<int> lps = LPS(pattern);
        int i = 0;
        int j = 0;

        while (i < n) {
            if (txt[i] == pattern[j]) {
                i++;
                j++;
            }
            if (j == m) {
                return true;
            } else if (i < n && txt[i] != pattern[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (searchPattern(words[j], words[i])) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};