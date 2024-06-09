class Solution {
public:

    bool canJump(vector<int>& nums) {
        int n= nums.size();
        int goal = n - 1; // placing our goal at the last position
        for (int i = n - 1; i >= 0; i--) { // running a reverse loop
            if (i + nums[i] >=goal) // if the current element be added to current index, can
                                    // it reach or surpass the goal?
                goal = i; // if yes then we update our goal to the current index
                          // as if we can reach the current index, we can reach
                          // the end as well, if not we move to the next index
                          // and check the same again.
        }
        // the goal has shifted to the first element (position we start from)
        // then we can reach our original goal.
        if (goal == 0)
            return true;
        return false;
    }
};