class Solution {
public:
    int mapNumber(int num, vector<int>& mapping) {
        if (num == 0) {
            return mapping[0];
        }
        
        int mapped_num = 0;
        int place = 1;
        
        while (num > 0) {
            int digit = num % 10;
            mapped_num = mapping[digit] * place + mapped_num;
            num /= 10;
            place *= 10;
        }
        
        return mapped_num;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> mapped_nums;
        
        for (int num : nums) {
            int mapped_val = mapNumber(num, mapping);
            mapped_nums.push_back({mapped_val, num});
        }
        
        sort(mapped_nums.begin(), mapped_nums.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 return a.first < b.first;
             });
    
        vector<int> result;
        for (auto& p : mapped_nums) {
            result.push_back(p.second);
        }
        
        return result;
    }
};