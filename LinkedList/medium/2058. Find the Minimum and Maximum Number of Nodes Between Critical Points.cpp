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
    int length(ListNode* head) {
        if (head == NULL)
            return 0;
        int count = 0;
        while (head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int len = length(head);
        cout << len << endl;
        if (len < 3)
            return {-1, -1};
        vector<int> ans;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next_curr = head->next->next;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int left = -1;
        int right = -1;
        int count = 1;
        while (next_curr) {
            count++;
            if (prev->val < curr->val && curr->val > next_curr->val) {
                left = count;
                ans.push_back(left);
            }
            if (prev->val > curr->val && curr->val < next_curr->val) {
                right = count;
                ans.push_back(right);
            }

            prev = prev->next;
            curr = curr->next;
            next_curr = next_curr->next;
        }

        if (ans.size() < 2)
            return {-1, -1};
        sort(ans.begin(), ans.end());
        int min_diff = INT_MAX;
        int max_diff = INT_MIN;
        for (int i = 0; i < size(ans) - 1; i++) {
            min_diff = min(min_diff, ans[i + 1] - ans[i]);
        }
        return {min_diff, ans[size(ans) - 1] - ans[0]};
    }
};