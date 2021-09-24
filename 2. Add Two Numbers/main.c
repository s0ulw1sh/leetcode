/**
Description:

    You are given two non-empty linked lists representing two non-negative integers.
    The digits are stored in reverse order, and each of their nodes contains a single digit.
    Add the two numbers and return the sum as a linked list.
    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Definition:

    struct ListNode {
        int val;
        struct ListNode *next;
    };

Example:
    
    1.
    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 342 + 465 = 807.
    
    2.
    Input: l1 = [0], l2 = [0]
    Output: [0]
    
    3.
    Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    Output: [8,9,9,9,0,0,0,1]

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
