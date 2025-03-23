#define ll long long
#define MOD 1000000007 

class Solution {
public:
    ll dijkstra(int src, unordered_map<ll, vector<pair<ll, ll>>>& adj, int n) {
        vector<ll> dist(n, LLONG_MAX);
        vector<ll> ways(n, 0);

        dist[src] = 0;
        ways[src] = 1;

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, src}); // {distance, node}

        while (!pq.empty()) {
            auto [t, curr] = pq.top();
            pq.pop();

            if (t > dist[curr]) continue; 

            for (auto &[v, w] : adj[curr]) {
                if (t + w < dist[v]) {
                    dist[v] = t + w;
                    ways[v] = ways[curr];
                    pq.push({dist[v], v});
                } else if (t + w == dist[v]) {
                    ways[v] = (ways[v] + ways[curr]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<ll, vector<pair<ll, ll>>> adj;
        for (auto &r : roads) {
            ll u = r[0], v = r[1], w = r[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        return dijkstra(0, adj, n);
    }
};
