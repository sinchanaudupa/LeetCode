bool circularArrayLoop(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) continue;

        bool forward = nums[i] > 0;
        int slow = i, fast = i;
        bool foundCycle = false;

        while (true) {
            // advance slow by 1
            if (nums[slow] == 0 || (nums[slow] > 0) != forward) break;
            int nextSlow = ((slow + nums[slow]) % numsSize + numsSize) % numsSize;
            if (nextSlow == slow) break;
            slow = nextSlow;

            // advance fast by 2
            if (nums[fast] == 0 || (nums[fast] > 0) != forward) break;
            int nextFast = ((fast + nums[fast]) % numsSize + numsSize) % numsSize;
            if (nextFast == fast) break;
            fast = nextFast;

            if (nums[fast] == 0 || (nums[fast] > 0) != forward) break;
            nextFast = ((fast + nums[fast]) % numsSize + numsSize) % numsSize;
            if (nextFast == fast) break;
            fast = nextFast;

            if (slow == fast) {
                foundCycle = true;
                break;
            }
        }

        if (foundCycle) return true;

        // mark the whole chain from i as visited so it's skipped in future iterations
        int j = i;
        while (nums[j] != 0 && (nums[j] > 0) == forward) {
            int next = ((j + nums[j]) % numsSize + numsSize) % numsSize;
            if (next == j) {
                nums[j] = 0;
                break;
            }
            int tmp = nums[j];
            nums[j] = 0;
            j = next;
        }
    }

    return false;
}