class Solution {
public:
    int countSubsetSum(vector<int>& nums, int sum, int n) {
        if (n == 0 and sum > 0)
            return 0;
        else if (n == 1) {
            if (sum == 0)
                return (nums[0] == 0) ? 2 : 1;
            else
                return nums[0] == sum;
        }
        else if (n==0 and sum==0) return 1; 

        int notTake = countSubsetSum(nums, sum, n - 1);
        int take = 0;
        if (nums[n-1] <= sum)
            take = countSubsetSum(nums, sum - nums[n-1], n - 1);
        return notTake + take;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // watch video of aditya verma, very simple
        // sum(subset1) - sum(remArray) = target
        // sum(subset1) + sum(remArray) = sum(of the entire array)
        // adding the 2 equation we get:
        // sum(subset1) = (sum + target)/2
        // now if we find no. of subsets with sum(subset1) that is the answer.

        int sum = 0;
        for (int i : nums)
            sum += i;

        if (abs(target) > sum or (target + sum) % 2 != 0)
            return 0;

        int subset1Sum = (target + sum) / 2;
        return countSubsetSum(nums, subset1Sum, nums.size());
    }
};