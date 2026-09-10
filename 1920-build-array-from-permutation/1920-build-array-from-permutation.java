class Solution {
    public int[] buildArray(int[] nums) {
        return IntStream.of(nums).map(i -> nums[i]).toArray();
    }
}