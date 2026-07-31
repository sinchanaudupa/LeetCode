/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decrypt(int* code, int codeSize, int k, int* returnSize) {
    
    int *result = malloc(codeSize * sizeof(int));
    *returnSize = codeSize;

    if (k == 0) {
        for (int i = 0; i < codeSize; i++) {
            result[i] = 0;
        }
        return result;
    }

    for (int i = 0; i < codeSize; i++) {
        result[i] = 0;

        if (k > 0) {
            for (int j = 1; j <= k; j++) {
                result[i] += code[(i + j) % codeSize];
            }
        }
        else {
            for (int j = 1; j <= -k; j++) {
                result[i] += code[(i - j + codeSize) % codeSize];
            }
        }
    }

    return result;
}