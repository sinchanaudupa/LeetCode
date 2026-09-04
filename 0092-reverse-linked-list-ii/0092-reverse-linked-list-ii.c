struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    
    if (head == NULL || left == right) {
        return head;
    }

    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode* prev = dummy;

    // Move prev to the node before 'left'
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    // curr is the first node we need to reverse
    struct ListNode* curr = prev->next;

    // Reverse from left to right
    for (int i = 0; i < right - left; i++) {
        struct ListNode* next = curr->next;

        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }

    return dummy->next;
}