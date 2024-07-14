class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string, int>());
        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                st.push(unordered_map<string, int>());
                i++;
            } else if (formula[i] == ')') {
                auto curr = st.top();
                st.pop();
                i++;
                string mult;
                while (i < n && isdigit(formula[i])) {
                    mult += formula[i];
                    i++;
                }
                int val = mult.empty() ? 1 : stoi(mult);
                for (auto &it : curr) {
                    st.top()[it.first] += it.second * val;
                }
            } else {
                string currElement;
                currElement.push_back(formula[i]);
                i++;
                while (i < n && isalpha(formula[i]) && islower(formula[i])) {
                    currElement.push_back(formula[i]);
                    i++;
                }
                string currCount;
                while (i < n && isdigit(formula[i])) {
                    currCount.push_back(formula[i]);
                    i++;
                }
                int currCountInteger = currCount.empty() ? 1 : stoi(currCount);
                st.top()[currElement] += currCountInteger;
            }
        }

        map<string, int> ans(begin(st.top()), end(st.top()));
        string result;
        for (auto it : ans) {
            result += it.first;
            if (it.second > 1) {
                result += to_string(it.second);
            }
        }

        return result;
    }
};
