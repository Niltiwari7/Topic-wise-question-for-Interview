class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream iss(s1);
        unordered_map<string, int> st1;
        string word;
        while (iss >> word) {
            st1[word]++;
        }
        unordered_map<string, int> st2;
        stringstream s(s2);
        while (s >> word) {
            st2[word]++;
        }
        vector<string> result;
        for (auto it : st1) {
            if ((st2.find(it.first) == st2.end()) && (st1[it.first] <= 1)) {
                result.push_back(it.first);
            }
        }
        for (auto& it : st2) {
            if ((st1.find(it.first) == st1.end()) && (st2[it.first] <= 1)) {
                result.push_back(it.first);
            }
        }
        return result;
    }
};