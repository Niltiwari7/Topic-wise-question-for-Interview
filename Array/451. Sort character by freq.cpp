class Solution {
public:
    string frequencySort(string s) {
     
       unordered_map<char,int>mp;
       for(auto ch:s){
           mp[ch]++;
       }
      priority_queue<pair<int,int>>pq;

      for(auto i:mp){
          pq.push({i.second,i.first});
      }  

      int j = 0;
      while(!pq.empty()){
          auto i = pq.top();pq.pop();
          cout<<i.first<<" "<<i.second<<endl;
          int temp = i.first;
          while(temp--){
              s[j++]=i.second;
          }
      }
      return s;
    }
};