class Solution {
public: 
    vector<string> buildArray(vector<int>& target, int n) {
    vector<string> result;
    stack<int> st;
    int j = 0;
    for (int i = 1; i <= n; i++) {
        st.push(i);
        result.push_back("Push");
        if (st.top() == target[j]) {
            j++;
        } else {
            st.pop();
            result.push_back("Pop");
        }
        if (j == target.size()) {
            break;
        }
    }
    return result;
}

};
