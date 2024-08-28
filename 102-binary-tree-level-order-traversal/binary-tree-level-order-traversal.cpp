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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; // Stores the final result (vector of vectors)
        if (!root) {
            return result; // Empty tree, return an empty result
        }

        queue<TreeNode*> q; // Queue for BFS traversal
        q.push(root); // Start with the root node

        // this queue will only terminate when there will be no childrens (i.e queue is empty)
        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes in the current level
            vector<int> levelValues; // Stores values of nodes at the current level

            // taking the stored level and pushing it in levelValues, while pushing it's children into the queue
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front(); // Get the front node from the queue
                q.pop(); // Remove it from the queue

                levelValues.push_back(curr->val); // Add its value to the current level

                // Push left and right children (if they exist) into the queue
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }

            result.push_back(levelValues); // Add the current level's values to the result
        }

        return result; // Return the final result
    }
};