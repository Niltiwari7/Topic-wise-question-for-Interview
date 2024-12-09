// Time Complexity : O(nlogn)
// Space Complexity : O(n)
class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>result;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1;i<intervals.size();i++){
            if(end>=intervals[i][0]){
                end = max(end,intervals[i][1]);
            }else{
                result.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        result.push_back({start,end});
        return result;
    }
};

