
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> mp;

        for (char ch : s) {
            mp[ch]++;
        }

        priority_queue<pair<char, int>> pq;
        for (auto it : mp) {
            pq.push({it.first, it.second});
        }

        string ans = "";
        while (!pq.empty()) {
            auto [ch, freq] = pq.top();
            pq.pop();

            int useCount = min(freq, repeatLimit); 

            for (int i = 0; i < useCount; i++) {
                ans += ch;
            }

            freq -= useCount; 
            if (freq > 0) {
                if (pq.empty()) {
                    break;
                }

                auto [nextCh, nextFreq] = pq.top();
                pq.pop();

                ans += nextCh; 
                nextFreq--;

           
                if (nextFreq > 0) {
                    pq.push({nextCh, nextFreq});
                }

              
                pq.push({ch, freq});
            }
        }

        return ans;
    }
};

