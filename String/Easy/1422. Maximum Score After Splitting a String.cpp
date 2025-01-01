class Solution {
public:
    int cntOne(string& s) {
        int cnt = 0;
        for (auto& ch : s) {
            cnt += (ch == '1');
        }
        return cnt;
    }
    int cntZero(string& s) {
        int cnt = 0;
        for (auto& ch : s) {
            cnt += (ch == '0');
        }
        return cnt;
    }

    int maxScore(string s) {
        int res = 0;
        for (int i = 1; i < s.size(); i++) {
            string l = s.substr(0, i);
            string r = s.substr(i);
            int cnt1 = cntZero(l);
            int cnt2 = cntOne(r);
            res = max(res, cnt1 + cnt2);
        }
        return res;
    }
};