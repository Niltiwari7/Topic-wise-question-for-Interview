
class Solution {
    public:
        bool isvowel(char ch) {
            return ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u';
        }
        long long countOfSubstrings(string word, int k) {
            int n = word.size();
            unordered_map<char, int> mp;
            vector<int> nextCons(n);
    
            int lastIdx = n;
            for (int i = n - 1; i >= 0; i--) {
                nextCons[i] = lastIdx;
                if (!isvowel(word[i])) {
                    lastIdx = i;
                }
            }
    
            int i = 0;
            int j = 0;
            long long res = 0;
            int cons = 0;
            while (j < n) {
                char ch = word[j];
                if (isvowel(ch)) {
                    mp[ch]++;
                } else {
                    cons++;
                }
                while (cons > k) {
                    char ch = word[i];
                    if (isvowel(ch)) {
                        mp[ch]--;
                        if (mp[ch] == 0) {
                            mp.erase(ch);
                        }
                    } else {
                        cons--;
                    }
                    i++;
                }
    
                while (i < n && mp.size() == 5 && cons == k) {
                    int idx = nextCons[j];
                    res += idx - j;
                    char ch = word[i];
                    if (isvowel(ch)) {
                        mp[ch]--;
                        if (mp[ch] == 0) {
                            mp.erase(ch);
                        }
                    } else {
                        cons--;
                    }
                    i++;
                }
                j++;
            }
            return res;
        }
    };