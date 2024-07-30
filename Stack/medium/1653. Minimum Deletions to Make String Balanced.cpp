class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!st.empty() && st.top() > s[i]) {
                count++;
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        return count;
    }
};