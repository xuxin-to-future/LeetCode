/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *p = head, *p2 = head;
    if(head == NULL) return NULL;
    bool hascycle = false;
    while(p2->next && p2->next->next){
        p = p->next;
        p2 = p2->next->next;
        if(p == p2){
            hascycle = true;
            break;
        }
    }
    if(hascycle){
        struct ListNode *q = head;
        while(p != q){
            p = p->next;
            q = q->next;
        }
        return q;
    }else{
        return NULL;
    }
}

