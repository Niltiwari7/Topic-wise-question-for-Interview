class Solution {
    public:
        string res = "";
    
        void solve(int i, string& pattern, vector<int>& nums,
                   unordered_set<int>& used, string temp) {
            if (i > pattern.size()) {
                if (res == "" || temp < res) {
                    res = temp;
                }
                return;
            }
    
            for (int num = 1; num <= 9; num++) {
                if (used.find(num) != used.end())
                    continue;
    
                if (i == 0 || (pattern[i - 1] == 'I' && nums[i - 1] < num) ||
                    (pattern[i - 1] == 'D' && nums[i - 1] > num)) {
    
                    nums[i] = num;
                    used.insert(num);
                    solve(i + 1, pattern, nums, used, temp + to_string(num));
                    used.erase(num);
                }
            }
        }
    
        string smallestNumber(string pattern) {
            int n = pattern.size();
            unordered_set<int> used;
            vector<int> nums(n + 1, -1);
            solve(0, pattern, nums, used, "");
            return res;
        }
    };
    