class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int _xor = 0;
        for(auto &ele:derived){
            _xor^=ele;
        }

        return _xor==0;
    }
};

// a = b^c
// b = a^c