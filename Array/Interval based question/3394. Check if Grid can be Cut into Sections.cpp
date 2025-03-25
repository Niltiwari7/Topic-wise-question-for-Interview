class Solution {
    public:
        vector<vector<int>>merge(vector<vector<int>>&interval){
            int n = interval.size();
            sort(begin(interval),end(interval));
    
            vector<vector<int>>result;
    
            result.push_back(interval[0]);
    
            for(int i = 1;i<n;i++){
                if(interval[i][0]<result.back()[1]){
                    result.back()[1] = max(result.back()[1],interval[i][1]);
                }else{
                    result.push_back(interval[i]);
                }
            }
            return result;
        }
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            if (n == 0) return false; 
    
            vector<vector<int>> xaxis, yaxis;
    
            for (auto& r : rectangles) {
                int x1 = r[0], y1 = r[1];
                int x2 = r[2], y2 = r[3];
                xaxis.push_back({x1, x2});
                yaxis.push_back({y1, y2});
            }
    
            vector<vector<int>>x = merge(xaxis);
            vector<vector<int>>y = merge(yaxis);
    
            return x.size() >= 3 || y.size() >= 3;
        }
    };
    