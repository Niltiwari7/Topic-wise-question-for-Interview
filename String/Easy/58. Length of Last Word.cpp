class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream str(s);
        vector<string>result;
        string word;
        while(str>>word){
            result.push_back(word);
        }
        return result[result.size()-1].size();
    }
};