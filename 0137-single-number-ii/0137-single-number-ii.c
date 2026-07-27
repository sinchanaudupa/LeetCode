int singleNumber(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        int freq = 0;

        for (int j = 0; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                freq++;
            }
        }

        if (freq == 1) {
            return nums[i];
        }
    }

    return -1;
}