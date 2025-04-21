class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int curr = 0;
            int maxVal = 0;
            int minVal = 0;
            for (auto& d : differences) {
                curr += d;
    
                minVal = min(minVal, curr);
                maxVal = max(maxVal, curr);
    
                if ((upper - maxVal) - (lower - minVal) + 1 <= 0) {
                    return 0;
                }
            }
    
            return (upper - maxVal) - (lower - minVal) + 1;
        }
    };