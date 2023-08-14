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
    ListNode* solve(ListNode* first, ListNode* second)
    {
        struct ListNode *curr1 = first;
        struct ListNode *curr2 = second;
        struct ListNode *next1 = first->next;
        while(next1 != NULL && curr2 != NULL){
            if(curr2->val >= curr1->val && curr2->val <= next1->val)
            {
                struct ListNode *next2 = curr2->next;
                curr1->next = curr2;
                curr2->next = next1;
                curr1 = curr2;
                curr2 = next2;
            }
            else
            {
                if(next1->next == NULL)
                {
                    next1->next = curr2;
                    return first;
                }
                else
                {
                     curr1 = curr1->next;
                     next1 = next1->next;
                }
            }
        }
        return first;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        struct ListNode *ptr1 = list1;
        struct ListNode *ptr2 = list2;
        struct ListNode *ptr3 = NULL;
        struct ListNode *ans;
        if(ptr1 == NULL && ptr2 == NULL)
        {
            return NULL;
        }
        else if(ptr1 == NULL)
        {
            return ptr2;
        }
        if(ptr2 == NULL)
        {
            return ptr1;
        }
        // else if(ptr1->next == NULL && ptr2->next == NULL)
        // {
        //     if(ptr1->val >= ptr2->val)
        //     {
        //         ptr2->next = ptr1;
        //         return ptr2;
        //     }
        //     else
        //     {
        //         ptr1->next = ptr2;
        //         return ptr1;
        //     }
        // }

        if(ptr1->val < ptr2->val)
        {
            if(ptr1->next == NULL)
            {
                ptr1->next = ptr2;
                return ptr1;
            }
            ans = solve(ptr1,ptr2);
            return ans;
        }
        else
        {
            if(ptr2->next == NULL)
            {
                ptr2->next = ptr1;
                return ptr2;
            }
            ans = solve(ptr2,ptr1);
            return ans;
        }
        
    }
};