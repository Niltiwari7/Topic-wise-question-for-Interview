// brute force approach
class Solution {
public:
    int dfs(int node , vector<vector<int>>&adj,vector<bool>&vis){
        vis[node] = true;
        int height = 0;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int size = q.size();
            int child = 0;
            while(size--){
                auto qNode = q.front();
                q.pop();
                for(auto neigh:adj[qNode]){
                    if(vis[neigh]==false){
                        q.push(neigh);
                        vis[neigh]=true;
                        child++;
                    }
                }
            }
            if(child>0){
                height+=1;
            }
        }
       return height;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
       vector<vector<int>>adj(n);
       for(auto edge:edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
       }  
        vector<int>result(n);
       for(int i = 0;i<n;i++){
        vector<bool>vis(n,false);
        result[i] = dfs(i,adj,vis);
       }
       int mini =INT_MAX;
       for(int i = 0;i<n;i++){
        mini = min(mini,result[i]);
       }
       vector<int>ans;
       for(int i = 0;i<result.size();i++){
        if(result[i]==mini){
            ans.push_back(i);
        }
       }
       return ans;
    }
};

// using topo sort
class Solution {
public:
   
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
       vector<vector<int>>adj(n);
       if(n==1)return {0};
       vector<int>indegree(n);
       for(auto edge:edges){
        int u = edge[0];
        int v = edge[1];
        indegree[u]++;
        indegree[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
       }  
        vector<int>result;
       queue<int>q;
       for(int i =0;i<n;i++){
        if(indegree[i]==1){
            q.push(i);
        }
       }
       while(n>2){
        int size = q.size();
        n-=size;
        while(size--){
            int u = q.front();
            q.pop();
            for(auto &it:adj[u]){
                indegree[it]--;
                if(indegree[it]==1){
                    q.push(it);
                }
            }
        }
       }
       while(!q.empty()){
        result.push_back(q.front());
        q.pop();
       }
       return result;
    }
};