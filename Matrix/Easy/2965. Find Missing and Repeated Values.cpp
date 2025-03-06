class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int rep = -1;
    
            unordered_set<int> st;
            for (auto row : grid) {
                for (auto ele : row) {
                    if (st.find(ele) != st.end()) {
                        rep = ele;
                    }
                    st.insert(ele);
                }
            }
    
            int count = 1;
            for (auto it : st) {
                if (st.find(count) == st.end()) {
                    break;
                } else {
                    count++;
                }
            }
    
            return {rep, count};
        }
    };