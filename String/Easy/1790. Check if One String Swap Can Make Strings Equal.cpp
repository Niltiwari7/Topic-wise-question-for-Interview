class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        if(s1.size()!=s2.size()){
            return false;
        }
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(int i = 0;i<s1.size();i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        for(int i = 0;i<s1.size();i++){
            if(s1[i]!=s2[i] ){
                count++;
            }
        }
        if(freq1==freq2){
            return count<=2;
        }
        return false;
    }
};