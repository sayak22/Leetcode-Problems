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
    TreeNode* build(vector<int>& pre, int preLow, int preHigh, vector<int>& in, int inLow, int inHigh) {
        // Base case: If the range is empty, return NULL (no subtree)
        if (preLow > preHigh || inLow > inHigh) {
            return nullptr;
        }

        // Create a new TreeNode with the value from the preorder array
        TreeNode* root = new TreeNode(pre[preLow]);

        // If it's a leaf node (preLow == preHigh), return the root
        if (preLow == preHigh) {
            return root;
        }

        // Find the index of the root value in the inorder array
        int i = inLow;
        while (i <= inHigh) {
            if (in[i] == pre[preLow]) {
                break;
            }
            i++;
        }

        // Calculate the count of nodes in the left subtree
        int leftCount = i - inLow;

        // Recurse on left and right subtrees
        root->left = build(pre, preLow + 1, preLow + leftCount, in, inLow, i - 1);
        root->right = build(pre, preLow + leftCount + 1, preHigh, in, i + 1, inHigh);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return build(preorder, 0, n - 1, inorder, 0, n - 1);
    }
};
