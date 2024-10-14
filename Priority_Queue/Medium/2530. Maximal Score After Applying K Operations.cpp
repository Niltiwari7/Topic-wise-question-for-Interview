class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long res = 0;
        priority_queue<long long> pq(nums.begin(), nums.end());
        while (k--) {
            long long ele = pq.top();
            pq.pop();
            res += ele;
            pq.push(ceil(ele / 3.0));
        }
        return res;
    }
};  