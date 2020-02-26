/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* p = head;
    while(p && p->next){
        struct ListNode* q = p->next;
        int temp = q->val;
        q->val = p->val;
        p->val = temp;
        p = p->next->next;
    }
    return head;
}

