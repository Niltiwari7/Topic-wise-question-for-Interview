class Solution {
public:
    string invert(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                s[i] = '1';
            else
                s[i] = '0';
        }
        return s;
    }

    string reverse__(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        if (n == 1 && k == 0) {
            return '0';
        }
        n -= 1;
        while (n > 0) {
            string temp = s + "1" + reverse__(invert(s));
            s = temp;
            n--;
        }
        return s[k - 1];
    }
};