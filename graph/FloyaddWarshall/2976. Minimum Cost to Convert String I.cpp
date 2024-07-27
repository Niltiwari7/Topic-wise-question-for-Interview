class Solution {
public:
    void makeGraph(vector<char>& o, vector<char>& t, vector<int>& cost, vector<vector<long long>>& grid) {
        int n = o.size();
        for (int i = 0; i < n; i++) {
            int s = o[i] - 'a';
            int d = t[i] - 'a';
            grid[s][d] = min(grid[s][d], 1LL * cost[i]);
        }

        for (int via = 0; via < 26; via++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (grid[i][via] != LLONG_MAX && grid[via][j] != LLONG_MAX) {
                        grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                    }
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> grid(26, vector<long long>(26, LLONG_MAX));
        
       
        for (int i = 0; i < 26; i++) {
            grid[i][i] = 0;
        }

        makeGraph(original, changed, cost, grid);

        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] == target[i]) continue;

            int s_val = source[i] - 'a';
            int t_val = target[i] - 'a';
            if (grid[s_val][t_val] == LLONG_MAX) {
                return -1; 
            }
            ans += grid[s_val][t_val];
        }
        return ans;
    }
};