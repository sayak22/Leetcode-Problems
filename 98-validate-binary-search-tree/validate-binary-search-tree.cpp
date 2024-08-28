class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long long prev = LLONG_MIN; // Initialize prev with negative infinity
        return isValidBSTHelper(root, prev);
    }

private:
    bool isValidBSTHelper(TreeNode* node, long long& prev) {
        if (!node) {
            return true; // Base case: nullptr node
        }

        // Recurse on left subtree
        if (!isValidBSTHelper(node->left, prev)) {
            return false;
        }

        // Check current node's value
        if (node->val <= prev) {
            return false;
        }
        prev = node->val; // Update prev

        // Recurse on right subtree
        return isValidBSTHelper(node->right, prev);
    }
};
