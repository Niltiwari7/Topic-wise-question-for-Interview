class Solution {
public:
    void fillCount(vector<int>& count, string s) {
        for (auto &ch : s) {
            count[ch - 'a']++;
        }
    }

    void updateCount(vector<int>& count, vector<int>& temp) {
        for (int i = 0; i < 26; i++) {
            count[i] = min(count[i], temp[i]);
        }
    }

    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int> count(26, 0);
        fillCount(count, words[0]);
        

        for (int i = 1; i < words.size(); i++) {
            vector<int> temp(26, 0);
            fillCount(temp, words[i]);
            updateCount(count, temp);
        }

       
        for (int i = 0; i < 26; i++) {
            while (count[i] > 0) {
                ans.push_back(string(1, 'a' + i));
                count[i]--;
            }
        }

        return ans;
    }
};
