// Time Complexity - O(n^3)
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

// Optimize approach
// Time Complexity - O(n^2)
// Space Complexity - O(n^2)

class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int> mp;
        int n = s.size();
        for (int i = 0; i < s.size(); i++) {
            char curr = s[i];
            int length = 0;
            for (int j = i; j < s.size(); j++) {
                if (curr == s[j]) {
                    length++;
                    mp[{curr, length}]++;
                } else {
                    break;
                }
            }
        }
        int res = 0;
        for (auto it : mp) {
            auto curr = it.first;
            char ch = curr.first;
            int cnt = curr.second;
            int freq = it.second;
            if (freq >= 3 && res < cnt) {
                res = cnt;
            }
        }
        return res == 0 ? -1 : res;
    }
};

// More Optimize way for solving this question

// Time Complexity - O(n)
// space Complexity - O(26*(length of string))
class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        vector<vector<int>> mat(26, vector<int>(n + 1, 0));
        char prev = s[0];
        int len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (prev == s[i]) {
                len++;
                mat[s[i] - 'a'][len]++;
            } else {
                len = 1;
                mat[s[i] - 'a'][len]++;
                prev = s[i];
            }
        }
        int res = 0;
        for (int row = 0; row < 26; row++) {
            int currSum = 0;
            for (int col = n; col >= 0; col--) {
                currSum += mat[row][col];
                if (currSum >= 3) {
                    res = max(res, col);
                }
            }
        }
        return res == 0 ? -1 : res;
    }
};