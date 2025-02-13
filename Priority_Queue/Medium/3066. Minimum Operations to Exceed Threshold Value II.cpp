class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long, vector<long long>, greater<>> pq;
            for (auto num : nums) {
                pq.push(num);
            }
            int ops = 0;
            while (pq.size() > 1 && pq.top() < k) {
                int first = pq.top();
                pq.pop();
                int second = pq.top();
                pq.pop();
    
                long long temp =
                    1LL * min(first, second) * 2 + 1LL * max(first, second);
                ops++;
                pq.push(temp);
            }
            return ops;
        }
    };