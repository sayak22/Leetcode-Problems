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
    void reorderList(ListNode* head) {
        // 1. Find the middle node (hare-tortoise approach)
        ListNode* slow = head, *fast = head;
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse the second half of the list
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while (secondHalf) {
            ListNode* next = secondHalf->next;
            secondHalf->next = prev;
            prev = secondHalf;
            secondHalf = next;
        }

        // 3. Merge the first and second halves
        ListNode* firstHalf = head;
        while (firstHalf and prev) {
            ListNode* firstNext = firstHalf->next;
            ListNode* prevNext = prev->next;
            firstHalf->next = prev;
            prev->next = firstNext;
            firstHalf = firstNext;
            prev = prevNext;
        }
    }
};