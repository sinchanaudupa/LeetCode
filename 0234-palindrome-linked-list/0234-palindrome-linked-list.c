/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool isPalindrome(struct ListNode* head) {
    // Count length
    int len = 0;
    struct ListNode* p = head;
    while (p) {
        len++;
        p = p->next;
    }
    
    // Create stack of exact size
    int stack[len];
    int top = 0;
    
    // Push all values
    p = head;
    while (p) {
        stack[top++] = p->val;
        p = p->next;
    }
    
    // Compare
    p = head;
    while (p) {
        if (p->val != stack[--top]) {
            return false;
        }
        p = p->next;
    }
    
    return true;
}