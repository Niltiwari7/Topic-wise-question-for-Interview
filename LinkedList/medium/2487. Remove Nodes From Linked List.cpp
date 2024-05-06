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
        ListNode *prev = NULL, *temp, *curr = head;
        while (curr != NULL) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        if (head == nullptr)
            return nullptr;
        while (head != NULL) {
            while (!st.empty() && st.top() < head->val) {
                st.pop();
            }
            st.push(head->val);
            head = head->next;
        }
        ListNode* l = new ListNode(-1);
        ListNode* curr = l;
        while (!st.empty()) {
            curr->next = new ListNode(st.top());
            st.pop();
            curr = curr->next;
        }
        return reverse(l->next);
    }
};