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
    vector<int> nodes;
    void Inorder(TreeNode* root) {
        if (!root)
            return;
        Inorder(root->left);
        nodes.push_back(root->val);
        Inorder(root->right);
    }
    TreeNode* solve(int low, int high) {
        if (low > high)
            return NULL;
        int mid = (low + high) / 2;
        TreeNode* node = new TreeNode(nodes[mid]);
        node->left = solve(low, mid - 1);
        node->right = solve(mid + 1, high);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        Inorder(root);
        return solve(0, nodes.size() - 1);
    }
};