/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(head==NULL or head->next==NULL)
        return false;

        ListNode* fast= head;
        ListNode* slow=head;

        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast == slow){
                //cycle detected
                return true;
            }
        }
        return false;
    }
};