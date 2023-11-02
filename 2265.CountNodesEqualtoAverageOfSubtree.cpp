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
    int length(TreeNode* root)
    {
        if(!root)return 0;
        return 1+length(root->left)+length(root->right);
    }
    int pathSum(TreeNode* root){
        if(!root){
            return 0;
        }
        int lh=pathSum(root->left);
        int rh=pathSum(root->right);
        return root->val+lh+rh;
    }
    void inOrder(TreeNode* root ,int &ans)
    {   if(!root) return;
        inOrder(root->left,ans);
        if(pathSum(root)/length(root)==root->val){
            ans++;
        }
        inOrder(root->right,ans);
    }
    int averageOfSubtree(TreeNode* root) {
       int ans=0;
       inOrder(root,ans); 
       return ans;
    }
};
