class Solution {
public:
    bool isSquare(int x) {
        long long sqr = sqrt(x);
        return 1LL*sqr * sqr == x;
    }
    bool judgeSquareSum(int c) {
        if(c==0)return true;
        for (long long i = 1; i * i <= c; i++) {
            if (isSquare(c - (i * i)))
                return true;
        }
        return false;
    }
};