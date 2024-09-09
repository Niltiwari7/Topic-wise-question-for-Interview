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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int>(n, -1));
        if (head == NULL) {
            return {};
        }
        int left = 0;
        int top = 0;
        int right = n - 1;
        int bottom = m - 1;
        ListNode* curr = head;
        while (left <= right && top <= bottom && curr != NULL) {
            for (int i = left; i <= right; i++) {
                if (curr == NULL)
                    break;
                mat[top][i] = curr->val;
                curr = curr->next;
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                if (curr == NULL)
                    break;
                mat[i][right] = curr->val;
                curr = curr->next;
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    if (curr == NULL)
                        break;
                    mat[bottom][i] = curr->val;
                    curr = curr->next;
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    if (curr == NULL)
                        break;
                    mat[i][left] = curr->val;
                    curr = curr->next;
                }
                left++;
            }
        }
        return mat;
    }
};