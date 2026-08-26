bool circularArrayLoop(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) continue;

        bool forward = nums[i] > 0;

        // Floyd's Cycle Detection (Tortoise and Hare)
        int slow = i;
        int fast = i;

        while (true) {
            // move slow one step
            if (nums[slow] == 0 || (nums[slow] > 0) != forward) { slow = -1; break; }
            int next1 = ((slow + nums[slow]) % numsSize + numsSize) % numsSize;
            if (next1 == slow) { slow = -1; break; }   // self-loop, not allowed
            slow = next1;

            // move fast two steps
            if (nums[fast] == 0 || (nums[fast] > 0) != forward) { fast = -1; break; }
            int next2 = ((fast + nums[fast]) % numsSize + numsSize) % numsSize;
            if (next2 == fast) { fast = -1; break; }
            fast = next2;

            if (nums[fast] == 0 || (nums[fast] > 0) != forward) { fast = -1; break; }
            next2 = ((fast + nums[fast]) % numsSize + numsSize) % numsSize;
            if (next2 == fast) { fast = -1; break; }
            fast = next2;

            if (slow == fast) {
                // Tortoise and hare met -> cycle exists
                return true;
            }
        }

        // No cycle found starting at i: mark the whole path as visited (0)
        int j = i;
        while (nums[j] != 0 && (nums[j] > 0) == forward) {
            int next = ((j + nums[j]) % numsSize + numsSize) % numsSize;
            nums[j] = 0;
            if (next == j) break;
            j = next;
        }
    }

    return false;
}