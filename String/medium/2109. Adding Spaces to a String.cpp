class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int i = 0;
        int k = 0;
        for (int i = 0; i < s.size(); i++) {
            if (k < spaces.size() && spaces[k] == i) {
                ans += " ";
                k++;
            }
            ans += s[i];
        }
        return ans;
    }
};