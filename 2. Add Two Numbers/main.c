/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* newListNode(struct ListNode *from, int val)
{
    struct ListNode *node;
    
    node       = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->val  = val;
    node->next = NULL;
    
    if (from) {
        from->next = node;
    }
    
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int sum = 0;
    struct ListNode *el, *res;
    
    sum = l1->val + l2->val;
    
    el   = newListNode(NULL, sum % 10);
    res  = el;
    l1   = l1->next;
    l2   = l2->next;
    sum /= 10;
    
    while(l1 || l2 || sum) {
        if (l1) {
            sum += l1->val;
            l1   = l1->next;
        }
        
        if (l2) {
            sum += l2->val;
            l2   = l2->next;
        }
        
        el   = newListNode(el, sum % 10);
        sum /= 10;
    }
    
    return res;
}
