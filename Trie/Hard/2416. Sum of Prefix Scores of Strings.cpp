class Trie {
public:
    struct trieNode {
        trieNode* children[26];
        int countP; 
        trieNode() {
            countP = 0;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    trieNode* root;
    
    Trie() {
        root = new trieNode();
    }

    void insert(string& word) {
        trieNode* curr = root;
        for (auto ch : word) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new trieNode();
            }
            curr = curr->children[idx];
            curr->countP += 1;
        }
    }

    
    int getScore(string& word) {
        trieNode* curr = root;
        int score = 0;
        for (auto ch : word) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) {
                return 0;
            }
            curr = curr->children[idx];
            score += curr->countP;
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        Trie trie;

       
        for (string& word : words) {
            trie.insert(word);
        }
        vector<int> result;
        for (string& word : words) {
            result.push_back(trie.getScore(word));
        }

        return result;
    }
};
