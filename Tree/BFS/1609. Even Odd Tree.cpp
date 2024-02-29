/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkStrictlyIncreasing(vector<int>v){
        for(int i=1;i<v.size();i++){
            if(v[i-1]>=v[i])return false;
        }
        return true;
    }

    bool checkStrictlyDecreasing(vector<int>v){
        for(int i=1;i<v.size();i++){
            if(v[i-1]<=v[i]){
                return false;
            }
         }
         return true;
       
    }
    bool checkEven(vector<int>v){
        for(int i=0;i<v.size();i++){
            if(v[i]%2!=0)return false; 
        }
        return true;
    }
    bool checkodd(vector<int>v){
        for(auto it:v){
            if(it%2==0)return false;
        }
        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
       vector<vector<int>>v;

       queue<TreeNode*>q;
       q.push(root);
       while(!q.empty()){
           int n = q.size();
           vector<int>level;
           while(n--){
               TreeNode* node = q.front();
               q.pop();
               
               if(node->left)q.push(node->left);
               if(node->right)q.push(node->right);
               level.push_back(node->val);
           }
           v.push_back(level);
       } 

       for(int i=0;i<v.size();i++){
           if(i%2==0){
               if(!checkodd(v[i]) || ! checkStrictlyIncreasing(v[i]))return false;
           }else if(i%2==1){
               if(!checkEven(v[i])|| !checkStrictlyDecreasing(v[i])){
                   return false;
               }
           }
       }
       return true;
    }
};