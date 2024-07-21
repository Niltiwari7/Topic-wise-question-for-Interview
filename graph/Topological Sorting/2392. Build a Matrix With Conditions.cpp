//dfs
class Solution {
public:
    void dfs(int node,vector<int>&vis,unordered_map<int,vector<int>>&adj,stack<int>&st,bool &flag){
        vis[node] = 1;
        for(auto &it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,st,flag);
            }else if(vis[it]==1){
                flag = true;
                return;
            }
            
        }
        vis[node] = 2;
        st.push(node);
    }
    vector<int>topoSort(vector<vector<int>>&edges,int &n){
         unordered_map<int,vector<int>>adj;
         for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
         }    
         vector<int>vis(n+1,0);
         stack<int>st;
         bool flag= false;
         for(int i =1;i<=n;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st,flag);
                if(flag==true){
                    return {};
                }
            }
         }

         vector<int>ans;
         while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
         }
         return ans;

    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>row=topoSort(rowConditions,k);
        vector<int>col=topoSort(colConditions,k);
        if(row.empty() || col.empty())return {};
        vector<vector<int>>mat(k,vector<int>(k,0));
        for(int i = 0;i<k;i++){
            for(int j = 0;j<k;j++){
                if(row[i]==col[j]){
                    mat[i][j] = row[i];
                }
            }
        }
        return mat;
    }
};

// BFS 
class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& edges, int& n) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n + 1, 0);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                count++;
            }
        }
        vector<int> result;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                    count++;
                }
            }
        }
        if (count != n) {
            return {};
        }
        return result;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        vector<int> row = topoSort(rowConditions, k);
        vector<int> col = topoSort(colConditions, k);
        if (row.empty() || col.empty())
            return {};
        vector<vector<int>> mat(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (row[i] == col[j]) {
                    mat[i][j] = row[i];
                }
            }
        }
        return mat;
    }
};