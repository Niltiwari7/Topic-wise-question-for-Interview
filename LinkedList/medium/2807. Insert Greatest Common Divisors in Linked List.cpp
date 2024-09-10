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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode* curr = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr_d = dummy;
        while(curr!=NULL && curr->next!=NULL){
            int gcd = __gcd(curr->val,curr->next->val);
            curr_d->next = new ListNode(curr->val);
            curr_d->next->next = new ListNode(gcd);
            curr_d->next->next->next = new ListNode(curr->next->val);
            curr_d = curr_d->next->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};