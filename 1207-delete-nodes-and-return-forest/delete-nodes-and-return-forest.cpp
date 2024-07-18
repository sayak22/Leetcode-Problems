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



 // TC: O(N) [N is the number of nodes in the tree] 
 // SC: O(N+K) due to the recursion stack and set length, K is the number of elements in to_delete   
class Solution {
private:
    unordered_set<int> toDeleteSet; // Stores values to be deleted

    TreeNode* dfs(TreeNode* root, vector<TreeNode*>& res) {
        if (!root) return nullptr; // Base case: null node

        // Recurse on left and right subtrees
        root->left = dfs(root->left, res);
        root->right = dfs(root->right, res);

        if (toDeleteSet.count(root->val)) {
            // If this node should be deleted:
            // 1. Add its children to the result (if they exist).
            if (root->left) res.push_back(root->left);
            if (root->right) res.push_back(root->right);
            // 2. Mark this node for deletion by returning nullptr.
            return nullptr;
        }

        // Otherwise, keep this node in the tree.
        return root;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        for (int num : to_delete)
            toDeleteSet.insert(num);

        // Check if the root itself should be deleted
        if (!toDeleteSet.count(root->val))
            res.push_back(root);

        // Call the DFS function
        dfs(root, res);
        return res;
    }
};
