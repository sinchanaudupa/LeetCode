/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** result = malloc(numRows * sizeof(int*));
    *returnSize = numRows;
    *returnColumnSizes = malloc(numRows * sizeof(int));
    for (int i = 0; i < numRows; i++) {
        result[i] = malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
        result[i][0] = 1;
        for (int j = 1; j < i; j++) {
            result[i][j] = result[i - 1][j - 1]+ result[i - 1][j];
        }
        result[i][i] = 1;
    }
    return result;
}