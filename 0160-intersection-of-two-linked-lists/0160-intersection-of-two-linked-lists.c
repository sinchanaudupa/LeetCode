/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

    struct ListNode* pointerA = headA;
    struct ListNode* pointerB = headB;

    while (pointerA != pointerB) {

        if (pointerA == NULL)
            pointerA = headB;
        else
            pointerA = pointerA->next;

        if (pointerB == NULL)
            pointerB = headA;
        else
            pointerB = pointerB->next;
    }

    return pointerA;
}