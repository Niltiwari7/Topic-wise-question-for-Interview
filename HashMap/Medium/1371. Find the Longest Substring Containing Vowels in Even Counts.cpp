class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> state(5, 0);
        unordered_map<string, int> mp;
        string currState = "00000";
        mp[currState] = -1;
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') {
                state[0] = (state[0] + 1) % 2;
            } else if (s[i] == 'e') {
                state[1] = (state[1] + 1) % 2;
            } else if (s[i] == 'i') {
                state[2] = (state[2] + 1) % 2;
            } else if (s[i] == 'o') {
                state[3] = (state[3] + 1) % 2;
            } else if (s[i] == 'u') {
                state[4] = (state[4] + 1) % 2;
            }
            currState = "";
            for (int j = 0; j < 5; j++) {
                currState += to_string(state[j]);
            }
            if (mp.find(currState) != mp.end()) {
                result = max(result, i - mp[currState]);
            } else {

                mp[currState] = i;
            }
        }
        return result;
    }
};