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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head;
        ListNode* dummy = new ListNode(-1);
        if (head == NULL)
            return NULL;
        ListNode* dcurr = dummy;
        while (curr->val == 0) {
            curr = curr->next;
        }

        int sum = 0;
        while (curr != NULL) {
            sum += curr->val;
            if (curr->val == 0) {
                dcurr->next = new ListNode(sum);
                dcurr = dcurr->next;
                sum = 0;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};