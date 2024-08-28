/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Handle the case where the list has only one node or is empty.
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        
        // Calculate the length of the list.
        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        // Determine the position of the node to remove from the beginning.
        int positionToRemove = length - n;

        // If the node to remove is the head, update the head pointer.
        if (positionToRemove == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Traverse to the node just before the one to remove.
        temp = head;
        for (int i = 1; i < positionToRemove; ++i) {
            temp = temp->next;
        }

        // Remove the target node.
        ListNode* nodeToRemove = temp->next;
        temp->next = nodeToRemove->next;
        delete nodeToRemove;

        return head;
    }
};
