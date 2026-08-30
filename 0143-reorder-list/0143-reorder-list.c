/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return;

    // 1. Find the middle
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Reverse the second half
    struct ListNode *prev = NULL;
    struct ListNode *curr = slow->next;

    slow->next = NULL;

    while (curr != NULL) {
        struct ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // 3. Merge the two halves
    struct ListNode *first = head;
    struct ListNode *second = prev;

    while (second != NULL) {
        struct ListNode *temp1 = first->next;
        struct ListNode *temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}