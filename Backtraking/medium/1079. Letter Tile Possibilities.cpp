class Solution {
    public:
        unordered_set<string> result;
        void solve(string& tiles, vector<bool>& used, string curr) {
            result.insert(curr);
            for (int i = 0; i < tiles.size(); i++) {
                if (used[i])
                    continue;
                // try
                used[i] = true;
                curr.push_back(tiles[i]);
                // explore
                solve(tiles, used, curr);
    
                // undo
                used[i] = false;
                curr.pop_back();
            }
        }
        int numTilePossibilities(string tiles) {
            int n = tiles.size();
            vector<bool> used(n, false);
            string curr = "";
            solve(tiles, used, curr);
            return result.size() - 1;
        }
    };
    