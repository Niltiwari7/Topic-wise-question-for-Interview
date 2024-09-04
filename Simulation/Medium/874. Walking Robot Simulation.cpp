class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for (auto& o : obstacles) {
            string key = to_string(o[0]) + "_" + to_string(o[1]);
            st.insert(key);
        }

        int x = 0;
        int y = 0;
        int maxD = 0;
        // pointing to north
        pair<int, int> dir = {0, 1};

        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -2) { // left 90 degree
                dir = {-dir.second, dir.first};
            } else if (commands[i] == -1) {
                dir = {dir.second, -dir.first};
            } else { // move to dir step by step
                for (int step = 0; step < commands[i]; step++) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;
                    string key = to_string(newX) + "_" + to_string(newY);
                    if (st.find(key) != st.end()) {
                        break;
                    }
                    x = newX;
                    y = newY;
                }
            }
            maxD = max(maxD, x * x + y * y);
        }
        return maxD;
    }
};