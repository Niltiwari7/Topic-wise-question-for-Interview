#include <vector>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        vector<int> flip(n, 0); // to keep track of flips
        
        int flipCount = 0; // to store the current flip state
        for (int i = 0; i < n; i++) {
            // Flip count is updated based on the past flips affecting the current position
            if (i >= k) {
                flipCount ^= flip[i - k];
            }
            
            // If the current bit (after accounting for flipCount) is 0, we need to flip it
            if (nums[i] == flipCount) {
                // Check if there's enough space to flip k bits from the current position
                if (i + k > n) {
                    return -1; // Not enough space to flip
                }
                
                // Flip at this position
                flipCount ^= 1; // Toggle the flip state
                flip[i] = 1; // Mark this position as the start of a flip
                count++; // Increment the flip count
            }
        }
        
        return count;
    }
};
