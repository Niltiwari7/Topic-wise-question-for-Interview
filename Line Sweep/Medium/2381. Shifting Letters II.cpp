class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int sz = s.size();
        vector<long long> line(sz + 1, 0);
        for (auto sh : shifts) {
            int start = sh[0];
            int end = sh[1];
            int x = sh[2];
            if (x == 1) {
                line[start]++;
                line[end + 1]--;
            } else {
                line[start]--;
                line[end + 1]++;
            }
        }
        for (int i = 1; i <= sz; i++) {
            line[i] += line[i - 1];
        }

        for (int i = 0; i < sz; i++) {
            int increased = ((s[i] - 'a' + line[i]) % 26 + 26) % 26;
            s[i] = 'a' + increased;
        }
        return s;
    }
};