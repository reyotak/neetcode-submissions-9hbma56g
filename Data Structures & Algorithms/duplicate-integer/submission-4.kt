class Solution {
    fun hasDuplicate(nums: IntArray): Boolean {
        nums.sort()
        for ((index, num) in nums.withIndex()) {
            if (index == 0) continue
            if (num == nums[index - 1]) return true
        }
        return false
    }
}
