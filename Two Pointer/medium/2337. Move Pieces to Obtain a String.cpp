// Time Complexity - O(n)
// Space Complexity - O(1)
class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0;
        int j = 0;
        int n = target.size();
        while (i <= n && j <= n) {
            while (j < n && start[j] == '_')
                j++;
            while (i < n && target[i] == '_')
                i++;
            if (i == n || j == n) {
                return i == n && j == n;
            }
            if (start[j] != target[i])
                return false;
            if (target[i] == 'L') {
                if (j < i)
                    return false;
            } else {
                if (i < j)
                    return false;
            }
            i++;
            j++;
        }
        return true;
    }
};