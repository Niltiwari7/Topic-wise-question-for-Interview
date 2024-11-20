class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int countA = 0, countB = 0, countC = 0;
        for (char ch : s) {
            countA += (ch == 'a');
            countB += (ch == 'b');
            countC += (ch == 'c');
        }

        if (countA < k || countB < k || countC < k) return -1;

        int i = 0, j = 0, res = INT_MIN;
        int currentA = countA, currentB = countB, currentC = countC;

        while (j < n) {
            if (s[j] == 'a') currentA--;
            if (s[j] == 'b') currentB--;
            if (s[j] == 'c') currentC--;

            while (currentA < k || currentB < k || currentC < k) {
                if (s[i] == 'a') currentA++;
                if (s[i] == 'b') currentB++;
                if (s[i] == 'c') currentC++;
                i++;
            }

            res = max(res, j - i + 1);
            j++;
        }

        return n - res;
    }
};
