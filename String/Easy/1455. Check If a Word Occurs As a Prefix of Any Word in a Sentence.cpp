class Solution {
public:

    /**
     * Checks if the searchWord is a prefix of any word in the sentence.
     * Iterates through each word in the given sentence to determine if the 
     * searchWord is a prefix of that word. If found, returns the 1-based 
     * index of the word in the sentence. If not found, returns -1.
     */

    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> arr;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            
            arr.push_back(word);
        }
        for (int i = 0; i < arr.size(); i++) {
            int k = 0;
            //Check first char If is not equal then continue
            if (arr[i][0] != searchWord[k])
                continue;
            for (int j = 0; j < arr[i].size(); j++) {
                
                if (arr[i][j] != searchWord[k]) {
                    break;
                }
                if (arr[i][j] == searchWord[k])
                    k++;
                if (k == searchWord.size()) {
                    return i + 1;
                }
            }
        }
        return -1;
    }
};