/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;

        // Step 1: Create a new node for each original node and insert it after the original node.
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val); // Create a new node with the same value.
            newNode->next = curr->next; // Insert the new node after the original node.
            curr->next = newNode; // Update the original node's next pointer.
            curr = newNode->next; // Move to the next original node.
        }

        // Step 2: Assign random pointers for the new nodes.
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next; // Set random pointer for the new node.
            curr = curr->next->next; // Move to the next original node.
        }

        // Step 3: Separate the original list and the copied list.
        Node* newHead = head->next; // The head of the copied list.
        curr = head;
        while (curr) {
            Node* temp = curr->next; // Store the next node in the original list.
            curr->next = temp->next; // Update the original list's next pointer.
            if (temp->next)
                temp->next = temp->next->next; // Update the copied list's next pointer.
            curr = curr->next; // Move to the next original node.
        }

        return newHead; // Return the head of the copied list.
    }
};
