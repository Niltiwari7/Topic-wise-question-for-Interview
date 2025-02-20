class Solution {
    public:
        string res;
        void solve(int i, int sz, string& temp, unordered_map<string, int>& mp) {
            // Base case
            if (i == sz) {
                if (mp.find(temp) == mp.end()) {
                    res = temp;
                }
                return;
            }
    
            // try
            temp.push_back('0');
            // explore
            solve(i + 1, sz, temp, mp);
            // undo
            temp.pop_back();
            // try
            temp.push_back('1');
            // explore
            solve(i + 1, sz, temp, mp);
            // undo
            temp.pop_back();
        }
        string findDifferentBinaryString(vector<string>& nums) {
            unordered_map<string, int> mp;
            for (auto num : nums) {
                mp[num]++;
            }
            int sz = nums[0].size();
            string temp = "";
            solve(0, sz, temp, mp);
            return res;
        }
    };