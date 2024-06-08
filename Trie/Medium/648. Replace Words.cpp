//Brute force
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string, int> mp;
        for (auto& d : dictionary) {
            mp[d]++;
        }
        stringstream ss(sentence);

        string ans = "";

        string word;
        while (ss >> word) {
            string temp="";
            bool flag = false;
            for (int i = 0; i < word.size(); i++) {
                temp+=word[i];
                if(mp.find(temp)!=mp.end()){
                    flag = true;
                    break;
                }
            }
           if(flag)ans+=temp+" ";
           else ans+=word+" ";
        }
       return ans.substr(0,ans.size()-1);
    }
};

// using trie
class Solution {
public:
    struct trieNode{
        trieNode *children[26];
        bool isEnd;
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->isEnd = false;
        for(int i = 0;i<26;i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }
   trieNode* root; 
   void insert(string word){
        trieNode* curr = root;
        for(int i = 0;i<word.size();i++){
            int idx = word[i]-'a';
            if(curr->children[idx]==NULL){
              curr->children[idx] = getNode();

            }
            curr=curr->children[idx];
        }
        curr->isEnd = true;
    }

    string search(string word){
        trieNode* curr = root;
        for(int i = 0;i<word.size();i++){
            int idx = word[i]-'a';
            if(curr->children[idx]==NULL){
                return word;
            }
            curr = curr->children[idx];
            if(curr->isEnd){
                return word.substr(0,i+1);
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
      root = getNode();
      for(string &s:dictionary){
        insert(s);
      }   
      stringstream ss(sentence);
      string word;
      string result;
      while(ss>>word){
        result+=search(word)+" ";
      }
      result.pop_back();
      return result;
    }
};