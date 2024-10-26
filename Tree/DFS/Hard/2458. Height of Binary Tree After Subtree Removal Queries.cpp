//BRUTE FORCE
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
    TreeNode* remove_(TreeNode* root,int val){
        if(!root)return NULL;
        if(val==root->val){
            return NULL;
        }
        root->left = remove_(root->left,val);
        root->right = remove_(root->right,val);
        return root;
    }
    int height(TreeNode* p){
        if(!p)return 0;
        return 1 + max(height(p->left),height(p->right));
    }
     TreeNode* deepCopy(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* newRoot = new TreeNode(root->val);
        newRoot->left = deepCopy(root->left);
        newRoot->right = deepCopy(root->right);
        return newRoot;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& q) {
        vector<int>result;
        for(auto ele:q){
            TreeNode* temp = deepCopy(root);
            remove_(temp,ele);
            int h = height(temp)-1;
            result.push_back(h);
        }
        return result;
    }
};

//OPTIMIZE APPROACH
class Solution {
public:
    int level[1000001];             // Stores the level of each node
    int height[1000001];            // Stores the height of each node
    int levelMaxHt[1000001];        // Maximum height at each level
    int levelSecondMaxHt[1000001];  // Second maximum height at each level

    // Helper function to calculate heights and max heights at each level
    int findHeight(TreeNode* root, int l) {
        if (!root) {
            return 0;
        }

        level[root->val] = l;
        
        // Calculate height of the current node
        height[root->val] = 1 + max(findHeight(root->left, l + 1), findHeight(root->right, l + 1));
        
        // Update the maximum and second maximum heights at this level
        if (levelMaxHt[l] < height[root->val]) {
            levelSecondMaxHt[l] = levelMaxHt[l];
            levelMaxHt[l] = height[root->val];
        } else if (levelSecondMaxHt[l] < height[root->val]) {
            levelSecondMaxHt[l] = height[root->val];
        }

        return height[root->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // Populate height and level arrays
        findHeight(root, 0);

        vector<int> result;
        for (int node : queries) {
            int nodeL = level[node];
            
            // Calculate the result for the current query
            int tempResult = nodeL + (levelMaxHt[nodeL] == height[node] ? levelSecondMaxHt[nodeL] : levelMaxHt[nodeL]) - 1;
            result.push_back(tempResult);
        }

        return result;
    }
};