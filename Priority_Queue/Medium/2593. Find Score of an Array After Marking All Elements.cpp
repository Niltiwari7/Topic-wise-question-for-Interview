// Time Complexity - O(nlog(n))
// Space Complexity - O(n)
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        while (!pq.empty()) {
            auto [ele, idx] = pq.top();
            pq.pop();
            if (mp.find(idx) == mp.end()) {
                score += ele;
                mp[idx]++;
                if (idx > 0) { 
                    mp[idx - 1]++;
                 }
                if (idx < n - 1) {
                    mp[idx + 1]++;
                }
            }
        }
        return score;
    }
};