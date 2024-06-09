class Solution {
public:

    bool solve(vector<int>& nums, int n){
        if(n==0) return true;
        int index=n-1;
        for(int i=n-1 ;i>=0;i--){
            if(i+nums[i]>=index)
                index=i;
            
        }
            if (index==0) return true;
            return false;
    }

    bool canJump(vector<int>& nums) {
    // int ans = solve(nums, 0,nums.size());
    // return ans==1;
    return solve(nums, nums.size());
    }
};