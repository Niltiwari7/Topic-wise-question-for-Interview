class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        int j = 0;
        int i = 0;
        while (logs[i++] == "../")
            j++;
        for (int i = j; i < logs.size(); i++) {
            if (logs[i] == "../") {
                if (cnt <= 0)
                    continue;
                cnt--;
            } else if (logs[i] == "./") {
                continue;
            } else {
                cnt++;
            }
        }
        return cnt <= 0 ? 0 : cnt;
    }
};