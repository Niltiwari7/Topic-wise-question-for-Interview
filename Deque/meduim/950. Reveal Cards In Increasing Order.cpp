class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& desk) {
       sort(desk.rbegin(),desk.rend());
       deque<int>d;
       d.push_back(desk[0]);
       for(int i = 1;i<desk.size();i++){
        d.push_front(d.back());
        d.pop_back();
        d.push_front(desk[i]);
       } 
       vector<int>res(d.begin(),d.end());
       return res;
    }
};