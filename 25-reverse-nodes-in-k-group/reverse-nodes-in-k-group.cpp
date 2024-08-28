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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Initialize pointers for reversing k nodes at a time.
        ListNode* prevGroupEnd = nullptr;
        ListNode* currGroupStart = head;

        // Count the total number of nodes in the list.
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        // Reverse k nodes at a time.
        while (count >= k) {
            ListNode* prev = nullptr;
            ListNode* curr = currGroupStart;
            for (int i = 0; i < k; ++i) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Update pointers for the reversed group.
            if (prevGroupEnd)
                prevGroupEnd->next = prev;
            else
                head = prev; // Update head if this is the first group.
            currGroupStart->next = curr;

            // Move to the next group.
            prevGroupEnd = currGroupStart;
            currGroupStart = curr;
            count -= k;
        }

        return head;
    }
};
