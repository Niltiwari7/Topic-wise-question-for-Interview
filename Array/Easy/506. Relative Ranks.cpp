class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp(score.begin(), score.end());
        sort(temp.rbegin(), temp.rend());
        unordered_map<int, int> mp;
        for (int i = 0; i < temp.size(); i++) {
            mp[temp[i]] = i + 1;
        }
        vector<string> result;
        for (int i = 0; i < score.size(); i++) {
            int val = mp[score[i]];
            if (val == 1) {
                result.push_back("Gold Medal");
            } else if (val == 2) {
                result.push_back("Silver Medal");
            } else if (val == 3) {
                result.push_back("Bronze Medal");
            } else {
                string s = to_string(val);
                result.push_back(s);
            }
        }
        return result;
    }
};