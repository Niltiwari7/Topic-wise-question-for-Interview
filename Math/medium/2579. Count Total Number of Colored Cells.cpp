class Solution {
    public:
        long long coloredCells(int n) {
            if (n == 1)
                return 1;
    
            int mult = 4;
            long long res = 1;
            for (int i = 2; i <= n; i++) {
                res += mult;
                mult += 4;
            }
            return res;
        }
    };
    
    /*
    n = 1
    1
    n=2
    1 + 4
    n = 3
    1+4+8 = 13
    n = 4
    1+4+8+10 = 25
    n = 5
    1+4+8+10+18=41
     3 4
     1 5 13 25 41
      4 8  12 16
    */