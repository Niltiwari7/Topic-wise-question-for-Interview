class Solution {
public:
    TreeNode* solve(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& result) {
        if (!root) return NULL;

        // Traverse left and right subtrees
        root->left = solve(root->left, st, result);
        root->right = solve(root->right, st, result);

        // If the current node needs to be deleted
        if (st.find(root->val) != st.end()) {
            // If the left child exists, add it to result
            if (root->left != NULL) {
                result.push_back(root->left);
            }
            // If the right child exists, add it to result
            if (root->right != NULL) {
                result.push_back(root->right);
            }
            // Return NULL to delete this node
            return NULL;
        } else {
            // Return the current node if it doesn't need to be deleted
            return root;
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        unordered_set<int> st(to_delete.begin(), to_delete.end());

        // Perform the post-order traversal and delete nodes as necessary
        solve(root, st, result);

        // If the root itself is not deleted, add it to the result
        if (st.find(root->val) == st.end()) {
            result.push_back(root);
        }
        return result;
    }
};
