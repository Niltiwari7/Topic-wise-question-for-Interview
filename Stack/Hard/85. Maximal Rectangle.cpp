class Solution {
public:
    vector<int> getNSL(vector<int>& height) {
        stack<int> st;
        int n = height.size();
        vector<int> NSL(n);
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                NSL[i] = -1;
            } else {
                while (!st.empty() && height[st.top()] >= height[i]) {
                    st.pop();
                }
                if (st.empty()) NSL[i] = -1;
                else NSL[i] = st.top();
            }
            st.push(i);
        }
        return NSL;
    }
    
    vector<int> getNSR(vector<int>& height) {
        stack<int> s;
        int n = height.size();
        vector<int> NSR(n);
        for (int i = n - 1; i >= 0; i--) {
            if (s.empty()) {
                NSR[i] = n;
            } else {
                while (!s.empty() && height[s.top()] >= height[i]) {
                    s.pop();
                }
                if (s.empty()) NSR[i] = n;
                else NSR[i] = s.top();
            }
            s.push(i);
        }
        return NSR;
    }
    
    int findMaxArea(vector<int>& height) {
        int n = height.size();
        vector<int> NSR = getNSR(height);
        vector<int> NSL = getNSL(height);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, (NSR[i] - NSL[i] - 1) * height[i]);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> height(n);
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            height[i] = (matrix[0][i] == '1') ? 1 : 0;
        }
        maxArea = findMaxArea(height);
        for (int row = 1; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == '0') {
                    height[col] = 0;
                } else {
                    height[col] += 1;
                }
            }
            maxArea = max(maxArea, findMaxArea(height));
        }
        return maxArea;
    }
};
