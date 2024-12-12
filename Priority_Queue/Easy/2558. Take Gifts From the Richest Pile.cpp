// Time Complexity - O(nlog(n))
// Space Complexity - O(n)
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for (auto g : gifts) {
            pq.push(g);
        }
        long long sum = 0;
        while (!pq.empty() && k--) {
            auto ele = pq.top();
            pq.pop();
            int x = sqrt(ele);
            pq.push(x);
        }
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};