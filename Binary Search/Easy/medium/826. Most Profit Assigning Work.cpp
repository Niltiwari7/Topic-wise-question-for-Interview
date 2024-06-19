typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)
#define rfo(i, n) for (int i = n - 1; i >= 0; i--)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)x.size()

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
int drow[4] = {-1, 1, 0, 0};
int dcol[4] = {0, 0, -1, 1};
int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[8] = {-1, 0, 1, -1, -1, 0, 1, 1};

template <typename T> void debug_vector(const vector<T>& v) {
    for (const auto& x : v) {
        cout << x << " ";
    }
    cout << endl;
}

template <typename T> void debug_2d_vector(const vector<vector<T>>& v) {
    for (const auto& row : v) {
        for (const auto& x : row) {
            cout << x << " ";
        }
        cout << endl;
    }
}
class Solution {
public:
    int solve(vector<pair<int, int>>& v, int w) {
        int low = 0;
        int high = v.size() - 1;
        int ans = -1;
        cout << "w " << w << endl;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (v[mid].first <= w) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<pair<int, int>> v;
        int maxi = INT_MIN;
        for (int i = 0; i < d.size(); i++) {
            v.push_back({d[i], p[i]});
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < w.size(); i++) {
            int idx = solve(v, w[i]);
            int maxi = INT_MIN;
            if (idx != -1) {
                for (int i = 0; i <= idx; i++) {
                    maxi = max(maxi, v[i].second);
                }
                ans += maxi;
            }
        }
        return ans;
    }
};