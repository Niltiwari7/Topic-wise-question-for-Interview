class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5)
                five++;
            else if (bills[i] == 10) {
                ten++;
                five--;
            } else if (bills[i] == 20) {
                if (ten == 0) {
                    five -= 3;
                } else {
                    ten--;
                    five--;
                }
            }
            if (five < 0 || ten < 0) {
                return false;
            }
        }

        return true;
    }
};