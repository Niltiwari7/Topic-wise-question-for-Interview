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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> children;
        for (auto& v : d) {
            int parent = v[0];
            int child = v[1];
            int isLeft = v[2];
            if (mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }
            if (mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }
            if (isLeft == 1) {
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }
            children.insert(child);
        }

        for (auto v : d) {
            int parent = v[0];
            if (children.find(parent) == children.end()) {
                return mp[parent];
            }
        }
        return NULL;
    }
};