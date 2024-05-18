class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1); 
        //vector<int> left(n,1);
        //vector<int> right(n,1);
        
        // storing left products of each element excluding itself in ans
        for(int i=1; i<n; ++i){
            ans[i]=ans[i-1]*nums[i-1];
        }

        //for right we are not creating a seperate vector(although we can), we are updating it in a variable
        int right=1;
        for(int i=n-1; i>=0; --i){
            ans[i]*=right;
            right*=nums[i];
        }

        return ans;
    }
};