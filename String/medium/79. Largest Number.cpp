class Solution {
public:
    static bool comp(string& a, string& b) { return (a + b) > (b + a); }
    string largestNumber(vector<int>& nums) {
        vector<string> result;
        for (auto it : nums) {
            result.push_back(to_string(it));
        }
        sort(result.begin(), result.end(), comp);
        string ans;
        if(result[0]=="0")return "0";
        for (auto& it : result)
            ans += it;
        return ans;
    }
};