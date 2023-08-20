/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* h) {
        Node* h1 = h;
        Node* c1;
        Node* d = new Node(0);
        Node* c3 = d;
        Node* c2;
        while(h1 != NULL){
            Node* t = new Node(h1->val);
            c1 = h1->next;
            h1->next = t;
            t->next = c1;
            h1 = c1;
        }

        // while(h != NULL){
        //     cout  << h->val << " ";
        //     h = h->next;
        // }
        // cout << endl;
        h1 = h;

        while(h1 != NULL){
            if(h1->random)
            h1->next->random = h1->random->next;
            h1 = h1->next->next;
        }

        h1 = h;
        c2 = h1;
        while(h1 != NULL){
            c2 = c2->next->next;
            d->next = h1->next;
            h1->next = c2;
            h1 = c2;
            // if(!c2)
            d = d->next;
        }

        return c3->next;
    }
};