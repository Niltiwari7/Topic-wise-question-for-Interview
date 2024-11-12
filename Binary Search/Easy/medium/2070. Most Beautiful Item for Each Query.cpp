class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<pair<int, int>> max_beauty_up_to;
        int current_max_beauty = 0;

        for (const auto& item : items) {
            int price = item[0];
            int beauty = item[1];
            current_max_beauty = max(current_max_beauty, beauty);
            max_beauty_up_to.push_back({price, current_max_beauty});
        }

        vector<int> result;
        for (int q : queries) {
            auto it =
                upper_bound(max_beauty_up_to.begin(), max_beauty_up_to.end(),
                            make_pair(q, INT_MAX));

            if (it == max_beauty_up_to.begin()) {
                result.push_back(0); 
            } else {
                result.push_back(
                    prev(it)->second);
            }
        }

        return result;
    }
};