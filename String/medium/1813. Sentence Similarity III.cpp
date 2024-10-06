class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        stringstream ss(s1);
        string word;
        vector<string> temp1;
        while (ss >> word)
            temp1.push_back(word);
        stringstream jj(s2);
        vector<string> temp2;
        while (jj >> word)
            temp2.push_back(word);
        int start1=0,start2=0,end1=temp1.size()-1,end2=temp2.size()-1;
        while(start1<=end1 && start2<=end2){
            if(temp1[start1]==temp2[start2]){
                start1++;
                start2++;
            }else if(temp1[end1]==temp2[end2]){
                end1--;
                end2--;
            }else{
                return false;
            }
        }
        return true;
    }
};