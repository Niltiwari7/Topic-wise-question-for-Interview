class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> chairs(n, -1);
        int targetFriendArrivalTime = times[targetFriend][0];
        sort(times.begin(), times.end());
        for (auto it : times) {
            int arrival = it[0];
            int depart = it[1];
            for (int i = 0; i < n; i++) {
                if (chairs[i] <= arrival) {
                    chairs[i] = depart;
                    if (arrival == targetFriendArrivalTime) {
                        return i;
                    }
                    break;
                }
            }
        }
        return -1;
    }
};