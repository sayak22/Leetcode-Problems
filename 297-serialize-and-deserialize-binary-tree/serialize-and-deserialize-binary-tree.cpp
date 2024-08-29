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
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserializeHelper(iss);
    }
    
private:
    TreeNode* deserializeHelper(istringstream& iss) {
        string token;
        getline(iss, token, ',');
        if (token == "#") return nullptr; // Null placeholder
        TreeNode* node = new TreeNode(stoi(token));
        node->left = deserializeHelper(iss);
        node->right = deserializeHelper(iss);
        return node;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));