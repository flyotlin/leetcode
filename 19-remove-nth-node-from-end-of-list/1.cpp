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
        int sz = 1;
        ListNode *p = head;
        while (p->next) {
            p = p->next;
            sz++;
        }

        // head
        if (n == sz) {
            return head->next;
        }

        // middle and tail
        p = head;
        int count = sz-n-1;
        while (count--) {
            p = p->next;
        }
        p->next = p->next->next;
        return head;
    }
};