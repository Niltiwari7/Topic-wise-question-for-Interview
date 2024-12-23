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
    int solve(vector<int>& temp) {
        int count = 0;
        map<int, int> mp;
        vector<int> u;
        for (int i = 0; i < temp.size(); i++) {
            mp[temp[i]] = i;
            u.push_back(temp[i]);
        }
        sort(u.begin(), u.end());
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] != u[i]) {
                temp[mp[u[i]]] = temp[i];
                mp[temp[i]] = mp[u[i]];
                mp[u[i]] = i;
                temp[i] = u[i];
                count++;
            }
        }
        return count;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        int res = 0;
        q.push(root);
        int i = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;
            while (n--) {
                auto curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            res += solve(temp);
        }
        return res;
    }
};