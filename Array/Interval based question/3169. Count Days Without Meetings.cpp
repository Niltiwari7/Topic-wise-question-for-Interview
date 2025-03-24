class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            int res = 0;
    
            // Sort by start time first, then by end time
            sort(begin(meetings), end(meetings), [](vector<int>& v1, vector<int>& v2) {
                return v1[0] < v2[0];  
            });
    
            int free_time = 0;
            int last_end = 0;  
    
            for (int i = 0; i < meetings.size(); i++) {
                int start = meetings[i][0];
                int end = meetings[i][1];
    
                if (start > last_end + 1) {
                    free_time += (start - last_end - 1);  
                }
    
                last_end = max(last_end, end);  
            }
    
          
            if (last_end < days) {
                free_time += (days - last_end);
            }
    
            return free_time;
        }
    };
    
    
    