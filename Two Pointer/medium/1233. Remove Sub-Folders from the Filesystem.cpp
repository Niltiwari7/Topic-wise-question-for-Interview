class Solution {
public:
    bool isSubfolder(string s1, string s2) {
        if (s2.size() <= s1.size()) {
            return false;
        }
        if (s2.substr(0, s1.size()) == s1 && s2[s1.size()] == '/') {
            return true;
        }
        return false;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        int n = folder.size();
        int i = 0;
        
        while (i < n) {
            result.push_back(folder[i]);
            int j = i + 1;
            while (j < n && isSubfolder(folder[i], folder[j])) {
                j++;
            }
            i = j;
        }

        return result;
    }
};
