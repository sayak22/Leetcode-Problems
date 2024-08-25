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
    vector<int> post;
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* temp=root;
        if(root==NULL) return post;
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            post.push_back(temp->val);
        return post;
    }
};