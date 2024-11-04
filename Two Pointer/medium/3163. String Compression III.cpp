class Solution {
public:
    string compressedString(string word) {
        int i = 0;
        int j = 0;
        string res = "";
        while (i < word.size() && j < word.size()) {
            int count = 0;
            while (j < word.size() && word[i] == word[j]) {
                count++;
                j++;
                if (j == word.size())
                    break;
                if (count >= 9) {
                    res += to_string(count) + word[i];
                    i = j;
                    count = 0;
                    continue;
                }
            }

            res += to_string(count) + word[i];
            i = j;
        }
        return res;
    }
};