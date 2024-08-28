/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p and !q) // if both are NULL then return true (same)
            return true;
        else if (!p or !q) // else if just one of them is NULL then return false (diff) 
            return false;

        bool isLeftSame = isSameTree(p->left, q->left);
        bool isRightSame = isSameTree(p->right, q->right);

        // only if the left and right subtree are same and the current values are same we pass TRUE
        if (isLeftSame and isRightSame and p->val == q->val)
            return true;
        //else pass FALSE
        return false;
    }
};