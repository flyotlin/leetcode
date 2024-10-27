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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *arr[32];
        ListNode *p = head;

        int i = 0;
        arr[i++] = p;

        while (p->next) {
            p = p->next;
            arr[i++] = p;
        }

        if (i == n) {
            return head->next;
        }

        p = arr[i-n-1];
        p->next = p->next->next;
        return head;
    }
};