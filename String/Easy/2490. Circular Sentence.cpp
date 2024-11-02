class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string word;
        vector<string> res;
        while (ss >> word) {
            res.push_back(word);
        }
        for (int i = 0; i < res.size() - 1; i++) {
            int n = res[i].size();
            if (res[i][n - 1] != res[i + 1][0])
                return false;
        }

        int n = res.size();
        int sz = res[n - 1].size();
        return res[0][0] == res[n - 1][sz - 1];
    }
};