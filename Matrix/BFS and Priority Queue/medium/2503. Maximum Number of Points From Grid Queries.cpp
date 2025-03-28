class Solution {
    public:
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    /*

        // BFS solution TC = Q*O(M*N)   
        int bfs(vector<vector<int>>& grid, vector < vector<bool>> & vis,
                int target) {
            queue<pair<int, int>> q;
            q.push({0, 0});
            vis[0][0] = true;
            int res = 0;
            while (!q.empty()) {
                int n = q.size();
                while (n--) {
                    auto [x, y] = q.front();
                    q.pop();
                    if (grid[x][y] > target) {
                        continue;
                    }
                    res++;
                    for (auto d : dir) {
                        int nx = x + d.first;
                        int ny = y + d.second;
                        if (nx >= 0 && nx < grid.size() && ny >= 0 &&
                            ny < grid[0].size() && !vis[nx][ny] &&
                            grid[nx][ny] < target) {
                            q.push({nx, ny});
                            vis[nx][ny] = true;
                        }
                    }
                }
            }
            return res;
        }
    
        */

        // Priority Queue solution 
    
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int m = grid.size();
            int n = grid[0].size();
    
            int Q = queries.size();
            vector<int> ans(Q,0);
    
            vector<pair<int,int>>sortedQ;
    
            for(int i = 0;i<Q;i++){
                sortedQ.push_back({queries[i], i}); 
            }
    
            sort(sortedQ.begin(), sortedQ.end());
    
            priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
            vector<vector<bool>>vis(m,vector<bool>(n,false));
    
            int point = 0;
    
            pq.push({grid[0][0],0,0});
    
            vis[0][0] = true;
    
            for(int i = 0 ; i<Q;i++){
                int val = sortedQ[i].first;
                int idx = sortedQ[i].second;
                while(!pq.empty() && pq.top()[0]<val){
                   int i = pq.top()[1];
                   int j = pq.top()[2];
                   pq.pop();
                   point++;
    
                   for(auto d:dir){
                    int i_ = i+d[0];
                    int j_ = j+d[1];
    
                    if(i_>=0 && i_<m && j_>=0 && j_<n && !vis[i_][j_]){
                        pq.push({grid[i_][j_],i_,j_});
                        vis[i_][j_] = true;
                    }
                   }  
                }
                ans[idx] = point;
            }
    
          return ans;
        }
    };
    