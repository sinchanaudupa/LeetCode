int** flipAndInvertImage(int** image, int imageSize, int* imageColSize,
                         int* returnSize, int** returnColumnSizes) {
    *returnSize = imageSize;//ROWS
    *returnColumnSizes = imageColSize;

    for (int i = 0; i < imageSize; i++) {
        int left = 0;
        int right = imageColSize[i] - 1;
        while (left <= right) {

            // If both pointers meet (middle element in odd-length row)
            if (left == right) {
                image[i][left] ^= 1;   // Invert only
                break;
            }

            // Swap and invert simultaneously
            int temp = image[i][left];
            image[i][left] = image[i][right] ^ 1;
            image[i][right] = temp ^ 1;

            left++;
            right--;
        }
    }

    return image;
}