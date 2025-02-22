/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
 class Solution {
    public:
        TreeNode* solve(int& i, int d, string s) {
            if (i >= s.size()) {
                return NULL;
            }
    
            int j = i;
    
            while (j < s.size() && s[j] == '-') {
                j++;
            }
            int dash = j - i;
    
            if (d != dash) {
                return NULL;
            }
    
            int num = 0;
            i = j;
            while (i < s.size() && isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
                i++;
            }
    
            TreeNode* root = new TreeNode(num);
            root->left = solve(i, d + 1, s);
            root->right = solve(i, d + 1, s);
    
            return root;
        }
        TreeNode* recoverFromPreorder(string traversal) {
            int i = 0;
            return solve(i, 0, traversal);
        }
    };