/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans; // To store the postorder traversal result

    vector<int> postorder(Node* root) {
        if (root == nullptr)
            return ans; // Base case: empty tree

        // Recurse on each child node
        for (Node* child : root->children) {
            postorder(child);
        }

        // Process the current node (add its value to the result)
        ans.push_back(root->val);

        return ans;
    }
};