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
    vector<int> post; // To store the postorder traversal result

// TC:O(N), SC:O(H) recursive call stack for height of the tree.
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return post; // Base case: empty tree
        }

        // Recurse on the left subtree
        postorderTraversal(root->left);

        // Recurse on the right subtree
        postorderTraversal(root->right);

        // Process the current node (add its value to the result)
        post.push_back(root->val);

        return post;
    }
};
