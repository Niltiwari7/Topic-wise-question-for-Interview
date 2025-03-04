class Solution {
    public:
        bool checkPowersOfThree(int n) {
            string temp = "";
            while (n) {
                temp += to_string(n % 3);
                n /= 3;
            }
    
            for (auto ch : temp) {
                if (ch == '1' or ch == '0') {
                    continue;
                } else {
                    return false;
                }
            }
            return true;
        }
    };