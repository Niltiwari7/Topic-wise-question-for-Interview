class Solution {
public:
    long long find_sum(string s) {
        long long sum = 0;
        for (int i = 0; i < s.size(); i++) {
            sum += s[i] - '0';
        }
        return sum;
    }
    int getLucky(string s, int k) {
        string t = "";
        for (int i = 0; i < s.size(); i++) {
            t += to_string(s[i] - 'a' + 1);
        }
        long long sum = 0;
        while (k--) {
            sum = find_sum(t);
            t = to_string(sum);
        }
        return sum;
    }
};