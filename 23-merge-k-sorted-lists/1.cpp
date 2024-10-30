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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> q;

        ListNode *p;
        for (ListNode *node : lists) {
            p = node;
            while (p) {
                q.push(p->val);
                p = p->next;
            }
        }

        ListNode *head = nullptr;   // if head not null-initialized, would cause delete non-malloc()-ed memory
        ListNode *res = nullptr;
        while (!q.empty()) {
            // cout << q.top() << endl;
            if (!res) {
                res = new ListNode();
                head = res;
            } else {
                res->next = new ListNode();
                res = res->next;
            }
            res->val = q.top();
            q.pop();
        }

        return head;
    }
};