class Solution {
public:
    int count = 0; // Count of good nodes

    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return count;
    }

private:
    void dfs(TreeNode* node, int maxSoFar) {
        if (!node) {
            return; // Base case: nullptr node
        }

        if (node->val >= maxSoFar) {
            count++; // Current node is a good node
        }

        // Update maxSoFar for the recursive calls
        maxSoFar = max(maxSoFar, node->val);

        // Recurse on left and right subtrees
        dfs(node->left, maxSoFar);
        dfs(node->right, maxSoFar);
    }

};
