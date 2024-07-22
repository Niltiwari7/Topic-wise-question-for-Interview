class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> people;
        for (int i = 0; i < names.size(); i++) {
            people.push_back({heights[i], names[i]});
        }
        vector<string> result;

        sort(people.begin(), people.end(), greater<>());

        for (auto& [h, p] : people) {
            result.push_back(p);
        }

        return result;
    }
};