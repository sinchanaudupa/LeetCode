/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int countNodes(TreeNode root) {
        if (root == null) return 0;
        int l = leftHeight(root), r = rightHeight(root);
        if (l == r) return (1 << l) - 1;
        return 1 + countNodes(root.left) + countNodes(root.right);
    }

    int leftHeight(TreeNode n) {
        return n == null ? 0 : 1 + leftHeight(n.left);
    }

    int rightHeight(TreeNode n) {
        return n == null ? 0 : 1 + rightHeight(n.right);
    }
}