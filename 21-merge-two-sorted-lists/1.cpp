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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p1 = list1;
        ListNode *p2 = list2;
        if (!p1 && !p2) {
            return nullptr;
        }

        ListNode *res = nullptr, *p = nullptr;

        while (p1 && p2) {
            if (!p) {
                p = new ListNode();
                res = p;
            } else {
                p->next = new ListNode();
                p = p->next;
            }
            if (p1->val <= p2->val) {
                p->val = p1->val;
                p1 = p1->next;
            } else {
                p->val = p2->val;
                p2 = p2->next;
            }
        }

        if (!p) {
            p = (p2 == nullptr) ? p1 : p2;
            res = p;
        } else {
            p->next = (p2 == nullptr) ? p1 : p2;
        }

        return res;
    }
};