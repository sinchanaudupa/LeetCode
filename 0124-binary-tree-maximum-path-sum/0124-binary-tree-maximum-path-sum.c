int maxPath(struct TreeNode* root, int* maxSum) {
    if (root == NULL)
        return 0;

    int left = maxPath(root->left, maxSum);
    int right = maxPath(root->right, maxSum);

    if (left < 0) left = 0;
    if (right < 0) right = 0;

    int path = root->val + left + right;

    if (path > *maxSum)
        *maxSum = path;

    return root->val + (left > right ? left : right);
}

int maxPathSum(struct TreeNode* root) {
    int maxSum = root->val;
    maxPath(root, &maxSum);
    return maxSum;
}