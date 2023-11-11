/*There is a directed weighted graph that consists of n nodes numbered from 0 to n - 1. The edges of the graph are initially represented by the given array edges where edges[i] = [fromi, toi, edgeCosti] meaning that there is an edge from fromi to toi with the cost edgeCosti.

Implement the Graph class:

Graph(int n, int[][] edges) initializes the object with n nodes and the given edges.
addEdge(int[] edge) adds an edge to the list of edges where edge = [from, to, edgeCost]. It is guaranteed that there is no edge between the two nodes before adding this one.
int shortestPath(int node1, int node2) returns the minimum cost of a path from node1 to node2. If no path exists, return -1. The cost of a path is the sum of the costs of the edges in the path.*/

class Graph {
public:
    unordered_map<int,vector<pair<int,int>>>adj;
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        N=n;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int cost=edge[2];
            adj[u].push_back({v,cost});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u=edge[0];
        int v=edge[1];
        int cost=edge[2];
        adj[u].push_back({v,cost});
    }
    
    int shortestPath(int node1, int node2) {
     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int>result(N,INT_MAX);
        result[node1]=0;
        pq.push({0,node1});
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &vec:adj[node]){
                int adjNode=vec.first;
                int dist=vec.second;
                if(d+dist<result[adjNode]){
                    result[adjNode]=d+dist;
                    pq.push({d+dist,adjNode});
                }
            }
        }
        return result[node2]==INT_MAX?-1:result[node2];

    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
