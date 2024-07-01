typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef unordered_map<int, int> uimap;
typedef unordered_map<char, int> ucmap;
typedef priority_queue<int, vector<int>, greater<int>> min_pq; // Min-heap
typedef priority_queue<int> max_pq;                            // Max-heap

#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)
#define rfo(i, n) for (int i = n - 1; i >= 0; i--)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)x.size()
#define endl '\n'
#define fast_io()                                                              \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL)
#define precision(x) cout << fixed << setprecision(x)
#define bitcount(x) __builtin_popcount(x) // Number of set bits in an integer
#define gcd(a, b) __gcd(a, b)             // Greatest Common Divisor
#define lcm(a, b) (a * (b / gcd(a, b)))   // Least Common Multiple
#define sort_asc(v) sort(all(v))          // Sort in ascending order
#define sort_desc(v) sort(all(v), greater<int>()) // Sort in descending order

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
int drow[4] = {-1, 1, 0, 0};
int dcol[4] = {0, 0, -1, 1};
int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[8] = {-1, 0, 1, -1, -1, 0, 1, 1};

template <typename T> void debug_1d(const vector<T>& v) {
    for (const auto& x : v) {
        cout << x << " ";
    }
    cout << endl;
}

template <typename T> void debug_2d(const vector<vector<T>>& v) {
    for (const auto& row : v) {
        for (const auto& x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}

template <typename T1, typename T2>
void debug_map(const unordered_map<T1, T2>& m) {
    for (const auto& p : m) {
        cout << p.first << " : " << p.second << endl;
    }
}

template <typename T> void debug_set(const unordered_set<T>& s) {
    for (const auto& x : s) {
        cout << x << " ";
    }
    cout << endl;
}
class Solution {
public:
    void DFS(int node, vvi& adj, vector<bool>& vis) {
        vis[node] = true;
        for (auto& neigh : adj[node]) {
            if (!vis[neigh]) {
                vis[neigh] = true;
                DFS(neigh, adj, vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vvi result;
        vvi adj(n);
        for (auto& e : edges) {
            adj[e[1]].pb(e[0]);
        }
        Fo(i, 0, n) {
            vector<int> ancestor;
            vector<bool> vis(n, false);
            DFS(i, adj, vis);
            Fo(j, 0, sz(vis)) {
                if (j == i)
                    continue;
                if (vis[j] == true) {
                    ancestor.pb(j);
                }
            }
            result.pb(ancestor);
        }
        return result;
    }
};