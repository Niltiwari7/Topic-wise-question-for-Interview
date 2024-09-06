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
        unordered_map<int, int> mp;
        for (auto& it : nums) {
            mp[it]++;
        }
        ListNode* curr = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr_dummy = dummy;
        while (curr != NULL) {
            if (mp.find(curr->val) == mp.end()) {
                curr_dummy->next = new ListNode(curr->val);
                curr_dummy = curr_dummy->next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};