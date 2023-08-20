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
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* dummy = new ListNode(0);        
        ListNode* k = dummy;
        
        while(a && b){
            if(a->val < b->val){
                ListNode* c = a->next;
                dummy->next = a;
                a->next = NULL;
                a = c;
            }
            else{
                ListNode* c = b->next;
                dummy->next = b;
                b->next = NULL;
                b = c;
            }
            dummy = dummy->next;
        }
        
        while(a){
            ListNode* c = a->next;
            dummy->next = a;
            a->next = NULL;
            a = c;
            dummy = dummy->next;
        }
        
        while(b){
            ListNode* c = b->next;
            dummy->next = b;
            b->next = NULL;
            b = c;
            dummy = dummy->next;
        }
        
        return k->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& a) {
        int n = a.size();
        if(n == 0)return NULL;
        for(int i = n-2; i >= 0; i--){
            a[i] = merge(a[i],a[i+1]);
        }
        
        return a[0];
    }
};