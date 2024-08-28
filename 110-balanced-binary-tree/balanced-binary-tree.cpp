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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool ans=true;
        findBalance(root, ans);
        return ans;
    }

    int findBalance(TreeNode* root, bool& ans){
        if(!root) return NULL;

        int leftHeight=findBalance(root->left, ans);
        int rightHeight=findBalance(root->right, ans);

        if(abs(leftHeight-rightHeight)>1) ans= false;
        return max(leftHeight,rightHeight)+1;
    }
};