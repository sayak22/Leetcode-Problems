class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = -1;
        dfs(root, k, count, ans);
        return ans;
    }

private:
    void dfs(TreeNode* root, int k, int& count, int& ans) {
        if (!root) {
            return; // Base case: nullptr node
        }

        // Recurse on left subtree
        dfs(root->left, k, count, ans);

        // Update count and check if k matches
        count++;
        if (count == k) {
            ans = root->val;
            return; // Found the kth smallest element, no need to continue
        }

        // Recurse on right subtree
        dfs(root->right, k, count, ans);
    }
};
