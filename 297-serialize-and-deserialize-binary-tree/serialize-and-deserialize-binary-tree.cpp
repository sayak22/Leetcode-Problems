/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#"; // Null placeholder
        // Serialize the current node's value, left subtree, and right subtree
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // input string stream (istringstream) class treats string as a stream
        istringstream iss(data);
        return deserializeHelper(iss);
    }
    
private:
    TreeNode* deserializeHelper(istringstream& iss) {
        string token;
        getline(iss, token, ',');
        if (token == "#") return nullptr; // Null placeholder
        // Create a new node with the current value
        TreeNode* node = new TreeNode(stoi(token));
        // Recursively build left and right subtrees
        node->left = deserializeHelper(iss);
        node->right = deserializeHelper(iss);
        return node;
    }
};



// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));