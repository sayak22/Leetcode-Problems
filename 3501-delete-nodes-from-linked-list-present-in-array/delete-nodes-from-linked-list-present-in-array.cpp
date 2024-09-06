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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;

        if (!head || (!head->next && mp[head->val] > 0))
            return nullptr;

        ListNode *prev = new ListNode(0, head), *cur = head;
        head = prev;

        while (cur) {
            if (mp[cur->val] > 0) {
                prev->next = cur->next;
                ListNode* toDelete = cur;
                cur = cur->next;
                delete toDelete;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }

        return head->next;
    }
};