class Solution {
public:

    int goodNodes(TreeNode* root) {
        int count=0; // count number of good nodes
        dfs(root, INT_MIN, count);
        return count;
    }

private:
    void dfs(TreeNode* node, int maxSoFar, int &count) {
        if (!node) {
            return; // Base case: nullptr node
        }

        if (node->val >= maxSoFar) {
            count++; // Current node is a good node
        }

        // Update maxSoFar for the recursive calls
        maxSoFar = max(maxSoFar, node->val);

        // Recurse on left and right subtrees
        dfs(node->left, maxSoFar, count);
        dfs(node->right, maxSoFar, count);
    }

};
