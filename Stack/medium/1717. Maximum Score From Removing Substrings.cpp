class Solution {
public:
    int solve(string &s, char a, char b) {
        int count = 0;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && s[i] == b && st.top() == a) {
                st.pop();
                count++;
            } else {
                st.push(s[i]);
            }
        }
        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return count;
    }

    int maximumGain(string s, int x, int y) {
        int ca = 0;
        int cb = 0;
        if (x > y) {
            ca = solve(s, 'a', 'b');
            cb = solve(s, 'b', 'a');
        } else {
            cb = solve(s, 'b', 'a');
            ca = solve(s, 'a', 'b');
        }

        return ca * x + cb * y;
    }
};
