class Solution {
    public:
        string pushDominoes(string dominoes) {
            int n = dominoes.size();
    
            vector<int> rightClosestL(n);
            vector<int> leftClosestR(n);
            // move from left to right to find closestR
            for (int i = 0; i < n; i++) {
                if (dominoes[i] == 'R') {
                    leftClosestR[i] = i;
                } else if (dominoes[i] == '.') {
                    leftClosestR[i] = i > 0 ? leftClosestR[i - 1] : -1;
                } else {
                    leftClosestR[i] = -1;
                }
            }
    
            // move right to left ton fint right closest L
    
            for (int i = n - 1; i >= 0; i--) {
                if (dominoes[i] == 'L') {
                    rightClosestL[i] = i;
                } else if (dominoes[i] == '.') {
                    rightClosestL[i] = i < n - 1 ? rightClosestL[i + 1] : -1;
                } else {
                    rightClosestL[i] = -1;
                }
            }
    
            string result(n, '.');
            for (int i = 0; i < n; i++) {
                int distL = abs(i - leftClosestR[i]);
                int distR = abs(i - rightClosestL[i]);
                if (rightClosestL[i] == leftClosestR[i]) {
                    result[i] = '.';
                } else if (rightClosestL[i] == -1) {
                    result[i] = 'R';
                } else if (leftClosestR[i] == -1) {
                    result[i] = 'L';
                } else if (distL == distR) {
                    result[i] = '.';
                } else {
                    result[i] = distL < distR ? 'R' : 'L';
                }
            }
            return result;
        }
    };