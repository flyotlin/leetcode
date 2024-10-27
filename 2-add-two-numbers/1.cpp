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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *a = l1;
        ListNode *b = l2;

        ListNode *res = new ListNode();
        ListNode *p = res;

        int carry = 0;
        int v = 0;

        while (a && b) {
            v = a->val + b->val + carry;
            p->val = v % 10;
            carry = v / 10;

            if (carry || a->next || b->next) {
                p->next = new ListNode();
            }

            p = p->next;
            a = a->next;
            b = b->next;
        }

        while (a) {
            v = a->val + carry;
            p->val = v % 10;
            carry = v / 10;

            if (carry || a->next) {
                p->next = new ListNode();
            }

            p = p->next;
            a = a->next;
        }

        while (b) {
            v = b->val + carry;
            p->val = v % 10;
            carry = v / 10;

            if (carry || b->next) {
                p->next = new ListNode();
            }

            p = p->next;
            b = b->next;
        }

        // last carry
        if (p) {
            p->val = carry;
            p->next = NULL;
        }

        return res;
    }
};
