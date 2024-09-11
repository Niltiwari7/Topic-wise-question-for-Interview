class Solution {
public:
    int minBitFlips(int start, int goal) {
        int val = start^goal;
        return __builtin_popcount(val);
    }
};