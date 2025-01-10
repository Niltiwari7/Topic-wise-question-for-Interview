// Brute force
class Solution {
public:
    bool check(string a, string b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if (b.size() > a.size())
            return false;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return b.size() == j;
    }
    bool isValid(string& w, vector<string>& word) {
        for (auto s : word) {
            if (!check(w, s)) {
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        for (auto w1 : words1) {
            if (isValid(w1, words2)) {
                result.push_back(w1);
            }
        }
        return result;
    }
};

// Optimized

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> result;
        vector<int> freq(26, 0);
        for (auto w : words2) {
            vector<int> temp(26, 0);
            for (auto ch : w) {
                temp[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                freq[i] = max(freq[i], temp[i]);
            }
        }

        for (auto w : words1) {
            vector<int> temp(26, 0);
            for (auto ch : w) {
                temp[ch - 'a']++;
            }
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] > temp[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                result.push_back(w);
        }
        return result;
    }
};