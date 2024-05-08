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
    ListNode* reverse(ListNode* head) {
        ListNode *temp, *prev = NULL, *curr = head;
        while (curr != NULL) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        ListNode* l = new ListNode(-1);
        ListNode* curr = l;
        int carry = 0;
        head = reverse(head);
        while (head != NULL) {
            int val = 2 * head->val + carry;
            carry = val / 10;
            curr->next = new ListNode(val % 10);
            curr = curr->next;
            head = head->next;
        }
        if (carry)
            curr->next = new ListNode(carry);
        return reverse(l->next);
    }
};