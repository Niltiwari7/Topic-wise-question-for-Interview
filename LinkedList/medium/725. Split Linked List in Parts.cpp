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
    int length(ListNode* head){
        int cnt = 0;
        ListNode* curr = head;
        while(curr!=NULL){
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        vector<ListNode*>result(k,NULL);
        if(head==NULL)return result;
        int len = length(head);
        ListNode* curr = head;
        ListNode* prev =NULL;
        int rem_node = len%k;
        for(int i = 0;i<k;i++){
            result[i] = curr;
            for(int cnt=1;cnt<=(len/k)+(rem_node>0?1:0);cnt++){
                prev = curr; 
                curr = curr->next;
            }
            prev->next = NULL;
            rem_node--;
        }
        return result;
    }
};