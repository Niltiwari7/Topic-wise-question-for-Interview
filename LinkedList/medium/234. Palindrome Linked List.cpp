// Time complextity = O(n) space complexity - O(n)

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
    bool isPalindrome(ListNode* head) {
        vector<int>result;
        ListNode* curr = head;
        while(curr!=NULL){
            result.push_back(curr->val);
            curr=curr->next;
        }
        int i = 0;
        int j = result.size()-1;
        while(i<=j){
            if(result[i]!=result[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};


//Time compleixty - O(n) space Complexity - O(1)

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
    ListNode* midNode(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* pre=NULL,*curr=head,*temp;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=pre;
            pre = curr;
            curr=temp;
          
        }
        return pre;
    }

    bool Compare(ListNode* head1,ListNode* head2){
        while(head1!=NULL && head2!=NULL){
            if(head1->val!=head2->val)return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL)return false;
        if(head->next==NULL)return true;
        ListNode* mid = midNode(head);
        ListNode* l2 = mid->next;
        mid->next=NULL;
        l2 = reverseList(l2);
        return Compare(head,l2);
    }
};