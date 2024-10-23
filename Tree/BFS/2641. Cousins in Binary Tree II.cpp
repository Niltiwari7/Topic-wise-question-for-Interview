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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL)return NULL;
        vector<int>levelSum;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            while(n--){
              auto node = q.front();
              q.pop();
              sum+=node->val;
              if(node->left)q.push(node->left);
              if(node->right)q.push(node->right);
            }
            levelSum.push_back(sum);
        }

        q.push(root);
        root->val = 0;
        int i = 1;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto curr = q.front();
                q.pop();
                int siblingSum = (curr->left!=NULL ? curr->left->val:0)
                +(curr->right!=NULL ? curr->right->val:0);
                
                if(curr->left){
                    curr->left->val = levelSum[i]-siblingSum;
                    q.push(curr->left);
                }
                if(curr->right){
                    curr->right->val = levelSum[i]-siblingSum;
                    q.push(curr->right);
                }
            }
            i++;
        }
        return root;
    }
};