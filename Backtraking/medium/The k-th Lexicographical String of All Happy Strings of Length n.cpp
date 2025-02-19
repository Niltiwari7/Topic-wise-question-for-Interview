class Solution {
    public:
        vector<string> result;
        void solve(int n, string temp, string& s) {
            if (n == temp.size()) {
                result.push_back(temp);
                return;
            }
    
            for (int i = 0; i < 3; i++) {
                if (temp == "" || temp.back() != s[i]) {
                    temp.push_back(s[i]);
                    solve(n, temp, s);
                    temp.pop_back();
                }
            }
        }
        string getHappyString(int n, int k) {
            string s = "abc";
            solve(n, "", s);
            sort(begin(result), end(result));
            int len = result.size();
            if (len < k) {
                return "";
            }
            return result[k - 1];
        }
    };