class Solution {
public:
    char solveOps(vector<char>& values, char ops) {
        if (ops == '!') {
            return values[0] == 't' ? 'f' : 't';
        }
        // Handle '&'
        if (ops == '&') {
            return any_of(begin(values), end(values), [](char ch) { return ch == 'f'; }) ? 'f' : 't';
        }
        // Handle '|'
        if (ops == '|') {
            return any_of(begin(values), end(values), [](char ch) { return ch == 't'; }) ? 't' : 'f';
        }
        return 't'; // Default case, though this should not occur
    }

    bool parseBoolExpr(string expression) {
        int n = expression.length();
        stack<char> st;
        
        for (int i = 0; i < n; i++) {
            if (expression[i] == ',') continue; // Skip commas

            if (expression[i] == ')') {
                vector<char> temp;
                // Pop values until we find the opening parenthesis
                while (!st.empty() && st.top() != '(') {
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop(); // Remove the '('

                char ops = st.top(); // Get the operator
                st.pop(); // Remove the operator

                // Solve the expression with the operator and values
                st.push(solveOps(temp, ops));
            } else {
                st.push(expression[i]); // Push current character onto the stack
            }
        }
        
        // Convert the final result to boolean
        return st.top() == 't';
    }
};
