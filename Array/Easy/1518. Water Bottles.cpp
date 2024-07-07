class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if (numBottles < numExchange)
            return numBottles;
        int ans = numBottles;
        while (true) {
            ans += (numBottles / numExchange);
            int remaingBottles =
                (numBottles / numExchange) + (numBottles % numExchange);
            if (remaingBottles < numExchange)
                break;
            numBottles = remaingBottles;
        }
        return ans;
    }
};