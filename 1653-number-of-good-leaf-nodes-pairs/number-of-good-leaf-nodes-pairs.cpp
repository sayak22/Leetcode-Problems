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
private:
    int res = 0;

    // Helper function to perform depth-first search (DFS)
    vector<int> dfs(TreeNode* node, int distance) {
        vector<int> map(distance + 1, 0);

        // Base case: If the node is null, return an array of zeros
        if (node == nullptr)
            return map;

        // If the node is a leaf (both left and right children are null),
        // mark the distance of 1 in the map
        if (node->left == nullptr && node->right == nullptr)
            map[1] = 1;

        // Recursively compute the left and right subtrees
        vector<int> left = dfs(node->left, distance);
        vector<int> right = dfs(node->right, distance);

        // Calculate the number of valid pairs of leaf nodes
        for (int i = 1; i < distance; ++i) {
            for (int j = 1; j <= distance - i; ++j) {
                res += (left[i] * right[j]);
            }
        }

        // Update the map for distances greater than 1
        for (int i = 2; i <= distance; ++i) {
            map[i] += left[i - 1] + right[i - 1];
        }

        return map;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return res;
    }
};