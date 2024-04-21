class Solution {
public:
    void dfs(int node,vector<bool>&vis,vector<int>graph[]){
        vis[node] = true;
        for(auto it:graph[node]){
            if(!vis[it]){
                dfs(it,vis,graph);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>graph[n];
        for(int i = 0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>vis(n,false);
        dfs(source,vis,graph);
        return vis[destination];
    }
};