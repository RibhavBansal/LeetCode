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
    bool isPalindrome(ListNode* head) {
        // vector<ListNode*>v;

        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* prev = slow;
        ListNode* net;

        slow = slow->next;

        prev->next = NULL;

        while(slow)
        {
            net = slow->next;
            slow->next = prev;
            prev = slow;
            slow = net;
        }

        cout << prev->val << " " << head->val << endl;
        while(prev)
        {
            if(prev->val != head->val)
            {
                return false;
            }
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};