// Time Complexity O(nlog(n))
// Space Complexity O(n)
class Solution {
public:
    int findNext(vector<vector<int>>& events, int target) {
        int low = 0, high = events.size() - 1, res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (events[mid][0] > target) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
    int solve(int i,int k,vector<vector<int>>&events,vector<vector<int>>&dp){
        if (k == 2 || i >= events.size()) {
            return 0; 
        }
        
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
     
        int nextIndex = findNext(events,events[i][1]);
        int include = events[i][2]+solve(nextIndex,k+1,events,dp);
        int notInclude = solve(i+1,k,events,dp);
        return dp[i][k] = max(include,notInclude);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n = events.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        return solve(0,0,events,dp);
    }
};