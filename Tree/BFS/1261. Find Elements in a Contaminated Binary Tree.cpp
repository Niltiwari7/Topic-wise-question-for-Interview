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
 class FindElements {
    public:
        unordered_set<int> values;
        FindElements(TreeNode* root) {
            if (!root) {
                return;
            }
            root->val = 0;
            // values.insert(root->val);
            int level = 0;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                auto curr = q.front();
                values.insert(curr->val);
                q.pop();
                if (curr->left) {
                    curr->left->val = 2 * curr->val + 1;
                    q.push(curr->left);
                }
    
                if (curr->right) {
                    curr->right->val = 2 * curr->val + 2;
                    q.push(curr->right);
                }
            }
        }
    
        bool find(int target) { return values.find(target) != values.end(); }
    };
    
    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     Explaination -:
               0
               /\
              /  \
           1=2*0+1  2*0+2=2
            /\
           /  \
      3=2*1+1  2*1+2 = 4
      Observation -:
      -> If we have root node value then left node value = 2*curr->val+1
      -> If we have root node value then right node value = 2*curr->val+2
     2*-1+1 =
     */