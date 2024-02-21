## Using Dynamic programing

#include <vector>
#include <algorithm>

class Solution {
public:
    int solve(int i, std::vector<int>& h, int b, int l) {
        if (i == h.size() - 1) {
            return 0;
        }

        if (h[i + 1] <= h[i]) {
            return 1 + solve(i + 1, h, b, l);
        }

        int byBrick = 0;
        int byLadder = 0;

        if (h[i + 1] - h[i] <= b) {
            int diff = h[i + 1] - h[i];
            byBrick = 1 + solve(i + 1, h, b - diff, l);
        }

        if (l > 0) {
            byLadder = 1 + solve(i + 1, h, b, l - 1);
        }

        return std::max(byBrick, byLadder);
    }

    int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
        return solve(0, heights, bricks, ladders);
    }
};



class Solution {
public:
       int furthestBuilding(vector<int>& A, int bricks, int ladders) {
        priority_queue<int> pq;
        for (int i = 0; i < A.size() - 1; i++) {
            int d = A[i + 1] - A[i];
            if (d > 0)
                pq.push(-d);
            if (pq.size() > ladders) {
                bricks += pq.top();
                pq.pop();
            }
            if (bricks < 0)
                return i;
        }
        return A.size() - 1;
    }
};
