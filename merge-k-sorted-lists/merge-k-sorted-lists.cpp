class Solution {
public:
    struct Compare {
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
        return NULL;

        ListNode* dummy = new ListNode(0);
        ListNode* d = dummy;

        int n = lists.size();
        priority_queue<ListNode*,vector<ListNode*>,Compare>pq;
        
        for(int i = 0; i < n; i++){
            if(lists[i] != NULL)
            pq.push(lists[i]);
        }

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            dummy->next = new ListNode(it->val);
            dummy = dummy->next;

            if(it->next){
                pq.push(it->next);
            }
        }

        return d->next;
    }
};