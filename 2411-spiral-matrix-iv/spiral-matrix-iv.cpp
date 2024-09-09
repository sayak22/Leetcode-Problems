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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));

        int left = 0, right = n - 1, top = 0, bottom = m - 1;

        // Check for empty list
        if (!head) {
            return ans;
        }

        while (left <= right && top <= bottom) {
            // Filling topmost row
            for (int i = left; i <= right; i++) {
                if (head == nullptr) {
                    break;
                }
                ans[top][i] = head->val;
                head = head->next;
            }
            top++;

            // Check for empty list or end of matrix
            if (!head || top > bottom) {
                break;
            }

            // Filling rightmost column
            for (int i = top; i <= bottom; i++) {
                if (head == nullptr) {
                    break;
                }
                ans[i][right] = head->val;
                head = head->next;
            }
            right--;

            // Check for empty list or end of matrix
            if (!head || left > right) {
                break;
            }

            // Filling bottommost row
            for (int i = right; i >= left; i--) {
                if (head == nullptr) {
                    break;
                }
                ans[bottom][i] = head->val;
                head = head->next;
            }
            bottom--;

            // Check for empty list or end of matrix
            if (!head || top > bottom) {
                break;
            }

            // Filling leftmost column
            for (int i = bottom; i >= top; i--) {
                if (head == nullptr) {
                    break;
                }
                ans[i][left] = head->val;
                head = head->next;
            }
            left++;
        }

        return ans;
    }
};