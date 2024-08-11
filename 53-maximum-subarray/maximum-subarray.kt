class Solution {
    fun maxSubArray(nums: IntArray): Int {
        // Initialize maxSum and currentSum to the first element of the array
        var maxSum = nums[0]
        var currentSum = nums[0]

        // Iterate through the array starting from the second element
        for (i in 1 until nums.size) {
            // Update currentSum: either continue the subarray or start a new one
            currentSum = maxOf(nums[i], currentSum + nums[i])

            // Update maxSum if currentSum is greater
            maxSum = maxOf(maxSum, currentSum)
        }

        return maxSum
    }
}
