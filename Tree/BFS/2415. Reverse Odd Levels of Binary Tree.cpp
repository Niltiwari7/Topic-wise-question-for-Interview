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
    TreeNode* convertToTree(vector<int>& ans) {
        int n = ans.size();
        if (n <= 0) {
            return NULL;
        }

        TreeNode* d = new TreeNode(ans[0]);
        queue<TreeNode*> q;
        q.push(d);
        int i = 1;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (i < ans.size() && node->left == NULL) {
                node->left = new TreeNode(ans[i]);
                q.push(node->left);
                i++;
            }
            if (i < ans.size() && node->right == NULL) {
                node->right = new TreeNode(ans[i]);
                q.push(node->right);
                i++;
            }
        }
        return d;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;
            while (n--) {
                auto curr = q.front();
                temp.push_back(curr->val);
                q.pop();
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            if (count % 2 == 0) {
                for (auto it : temp) {
                    ans.push_back(it);
                }
            } else {
                reverse(temp.begin(), temp.end());
                for (auto it : temp)
                    ans.push_back(it);
            }
            count++;
        }
        return convertToTree(ans);
    }
};