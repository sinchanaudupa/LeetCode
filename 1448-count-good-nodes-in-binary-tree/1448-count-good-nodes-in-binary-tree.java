
class Solution {
    public int goodNodes(TreeNode root) {
        return countGood(root, Integer.MIN_VALUE);
    }

    public int countGood(TreeNode root, int max) {
        if (root == null) {
            return 0;
        }

        int count = 0;

        if (root.val >= max) {
            count = 1;
        }

        max = Math.max(max, root.val);

        count += countGood(root.left, max);
        count += countGood(root.right, max);

        return count;
    }
}
