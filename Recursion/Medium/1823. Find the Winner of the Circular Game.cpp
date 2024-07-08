class Solution {
public:
    int helper(int n, int k) {
        if (n == 1)
            return 0;
        int take = helper(n - 1, k) + k;
        return take % n;
    }
    int findTheWinner(int n, int k) 
    { 
        return helper(n, k) + 1;
    }
};