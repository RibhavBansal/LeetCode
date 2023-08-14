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
    bool hasCycle(ListNode *h) {
        if(!h || !h->next)
        return false;

        ListNode *s = h->next;
        ListNode *f = h->next->next;
        while(s != f)
        {
            if(!f || !f->next)
            return false;

            s = s->next;
            f = f->next->next;
        }

        return true;
    }
};