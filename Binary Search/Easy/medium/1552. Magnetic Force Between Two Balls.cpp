class Solution {
public:
    bool isPos(int mid, int m, vector<int>& nums) {
        int count = 1; 
        int lastPos = nums[0]; 
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - lastPos >= mid) {
                count++;
                lastPos = nums[i];
                if (count >= m) return true;
            }
        }
        return count >= m;
    }

    int maxDistance(vector<int>& p, int m) {
        sort(p.begin(), p.end());
        int low = 1;
        int high = p.back() - p.front(); 
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPos(mid, m, p)) {
                ans = mid;
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }
        return ans;
    }
};
