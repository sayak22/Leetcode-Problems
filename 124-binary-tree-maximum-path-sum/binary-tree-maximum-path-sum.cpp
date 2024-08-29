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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; // Initialize with the smallest possible value
        dfs(root, maxSum);
        return maxSum;
    }
    
    int dfs(TreeNode* node, int& maxSum) {
        if (!node) return 0;
        
        // Calculate the maximum path sum for the left and right subtrees
        int leftSum = max(0, dfs(node->left, maxSum));
        int rightSum = max(0, dfs(node->right, maxSum));
        
        // Update the overall maximum path sum
        maxSum = max(maxSum, leftSum + rightSum + node->val);
        
        // Return the maximum contribution from this node
        return max(leftSum, rightSum) + node->val;
    }
};
