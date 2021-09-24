/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* newListNode(struct ListNode *from)
{
    struct ListNode *node;
    
    node       = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val  = 0;
    node->next = NULL;
    
    if (from) {
        from->next = node;
    }
    
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int l1val,
        l2val,
        i = 0, acm;
    struct ListNode *el, *res;
    
    el  = newListNode(NULL);
    res = el;
    
    l1val = l1->val;
    l2val = l2->val;

    while(l1 || l2) {
        acm = l1val + l2val + i;
        
        el->val = acm % 10;
        i       = acm / 10;
        
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
        
        if (l1 || l2) {
            el = newListNode(el);

            l1val = l1 ? l1->val : 0;
            l2val = l2 ? l2->val : 0;
        }
    }
    
    if (i) {
        el = newListNode(el);
        el->val = i;
    }

    return res;
}
