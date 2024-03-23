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
        vector<ListNode*>arr;
        for(auto iter=head;iter;iter=iter->next) arr.push_back(iter);
        int L = 1, R = size(arr)-1;
        for(int i=0;i<size(arr);i++,head=head->next){
            if(i&1)
               head->next=arr[L++];
            else 
               head->next=arr[R--];
        }
        head->next=NULL;
    }

};