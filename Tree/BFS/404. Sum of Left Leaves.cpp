class Solution {
public:
    bool isLeaf(TreeNode* node) {
        return node && !node->left && !node->right; 
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;  
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                
                if (node->left) {
                    if (isLeaf(node->left)) 
                        sum += node->left->val;
                    else
                        q.push(node->left);
                }
                if (node->right) 
                    q.push(node->right);
            }
        }
        return sum;
    }
};
