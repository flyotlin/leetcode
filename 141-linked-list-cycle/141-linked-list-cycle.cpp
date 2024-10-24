/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<void *, bool> map;
        ListNode *p = head;
        if (p == nullptr) {
            return false;
        }

        while (p->next) {
            map[p] = true;
            // cout << p->val << " " << p << endl;
            p = p->next;
            if (map.find(p) != map.end()) {
                return true;
            }
        }
        return false;
    }
};