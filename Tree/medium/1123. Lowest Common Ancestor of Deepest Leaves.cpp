class Solution {
    public:
        unordered_map<int, int> mp;
        int maxD = 0;
    
        void depth(TreeNode* root, int h) {
            if (!root) return;
            mp[root->val] = h;
            maxD = max(maxD, h); 
            depth(root->left, h + 1);
            depth(root->right, h + 1);
        }
    
        TreeNode* LCA(TreeNode* root) {
            if (!root || mp[root->val] == maxD) {
                return root;
            }
    
            TreeNode* l = LCA(root->left);
            TreeNode* r = LCA(root->right);
    
            if (l && r) return root;
            return l ? l : r;
        }
    
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            depth(root, 0);           
            return LCA(root);        
        }
    };
    