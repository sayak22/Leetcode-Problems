class Solution {
public:
    /*
    ::::::::::::::::::::::::::
    RECCURSION + MEMORIZATION
    ::::::::::::::::::::::::::
    */
    // int solve(vector<int>& nums, int n, vector<int>& dp) {
    //     if (n <= 0)
    //         return 0;

    //     if (dp[n] != -1)
    //         return dp[n];
    //     //        max(NOT taking current element, taking current element)
    //     return dp[n] = max(solve(nums, n - 1, dp), nums[n - 1] + solve(nums,
    //     n - 2, dp));
    // }

    // int rob(vector<int>& nums) {

    //     if(nums.size()==1) return nums[0];
    //     vector<int> temp1, temp2;
    //     for(int i=0;i<nums.size();i++){
    //         if(i!=0) temp1.push_back(nums[i]);
    //         if(i!=nums.size()-1) temp2.push_back(nums[i]);
    //     }
    //     vector<int> dp1(temp1.size()+1,-1);
    //     vector<int> dp2(temp2.size()+1,-1);
    //     return max(solve(temp1, temp1.size(),dp1), solve(temp2,
    //     temp2.size(),dp2));
    // }

    /*
    :::::::::::::::::::::::::::::::::::::::::::::::::::::
    Tabulation (Bottom up uproach) [space optimized O(1)]
    :::::::::::::::::::::::::::::::::::::::::::::::::::::
    */
int solve(vector<int>& nums) {
    // Initialize variables to store the maximum money that can be robbed
    // prev2 represents dp[i-2], prev represents dp[i-1], curi represents dp[i]
    int prev2 = 0, prev = 0, curi;

    // Iterate through each house in the array
    for (int i = 0; i < nums.size(); i++) {
        // Calculate the money if we take the current house
        int take = nums[i] + prev2;
        // Calculate the money if we don't take the current house
        int notTake = 0 + prev;
        // The current maximum money is the maximum of taking or not taking the current house
        curi = max(take, notTake);
        // Update prev2 and prev for the next iteration
        prev2 = prev;
        prev = curi;
    }
    // Return the maximum money that can be robbed, which is stored in prev
    return prev;
}

// Function to solve the problem for a circular array of houses
int rob(vector<int>& nums) {
    // If there's only one house, return its value
    if (nums.size() == 1)
        return nums[0];

    // Create two temporary arrays to handle the circular nature
    vector<int> temp1, temp2;
    for (int i = 0; i < nums.size(); i++) {
        // Exclude the first house for temp1
        if (i != 0)
            temp1.push_back(nums[i]);
        // Exclude the last house for temp2
        if (i != nums.size() - 1)
            temp2.push_back(nums[i]);
    }

    // Return the maximum money that can be robbed from either temp1 or temp2
    return max(solve(temp1), solve(temp2));
}
};
