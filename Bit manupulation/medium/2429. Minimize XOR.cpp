class Solution {
public:
    int minimizeXor(int num1, int num2) {
        if (num1 == num2) {
            return num1;
        }
        int ans = 0;
        int bit = __builtin_popcount(num2);
        for (int i = 31; i >= 0; i--) {
            int currBit = (num1 >> i) & 1;
            if (currBit == 1 && bit > 0) {
                ans |= (1 << i);
                bit--;
            }
        }

        for (int i = 0; i < 32; i++) {
            if (bit == 0)
                break;
            int currBit = (ans >> i) & 1;
            if (currBit == 0) {
                ans |= (1 << i);
                bit--;
            }
        }
        return ans;
    }
};