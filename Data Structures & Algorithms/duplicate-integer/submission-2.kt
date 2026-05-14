class Solution {
    fun hasDuplicate(nums: IntArray): Boolean {
        for (index in 0 until nums.size) {
            var num = nums[index]
            for (nextIndex in index + 1 until nums.size) {
                if (num == nums[nextIndex]) return true
            }
        }
        return false
    }
}
