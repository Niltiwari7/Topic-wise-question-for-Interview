class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            freq1[s1[i] - 'a']++;
        }
        string str1 = "";
        for (auto it : freq1) {
            str1 += (to_string(it) + "#");
        }

        int i = 0;
        int j = 0;
        vector<int> tempFreq(26, 0);
        while (j < s2.size()) {
            tempFreq[s2[j] - 'a']++;
            while (j - i + 1 > s1.size()) {
                tempFreq[s2[i] - 'a']--;
                i++;
            }
            if (j - i + 1 == s1.size()) {
                string temp = "";
                for (auto it : tempFreq) {
                    temp += (to_string(it) + "#");
                }
                // cout<<i<<" "<<j<<" "<<temp<<endl;
                if (temp == str1) {
                    return true;
                }
            }
            j++;
        }
        return false;
    }
};