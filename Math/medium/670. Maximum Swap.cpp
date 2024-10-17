class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int maxi = INT_MIN;
        int left_idx = -1;
        int right_idx = -1;
        int max_idx = INT_MAX;
        for (int i = s.size()-1; i >=0; i--) {
            int temp = s[i] - '0';
            if (maxi < temp) {
                maxi = s[i] - '0';
                max_idx = i;
                continue;
            }
           if(temp<maxi){
            left_idx = i;
            right_idx = max_idx;
            
           }
        }
        if(left_idx==-1)return num;
        swap(s[left_idx], s[right_idx]);
        num = stoi(s);
        return num;
    }
};