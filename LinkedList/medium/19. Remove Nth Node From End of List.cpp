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
 int length(ListNode* head){
     if(head==NULL)return 0;
     int count = 0;
     while(head!=NULL){
         count+=1;
         head=head->next;
     }
     return count;
 }
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
         
        ListNode *curr= head;
        if(n==0)
        {
            return head->next;
        }
        if(len==n)return head->next;
         
        for(int i = 1;i<len-n;i++){
            curr=curr->next;
        }
        curr->next=curr->next->next;      
        return head;
    }
};