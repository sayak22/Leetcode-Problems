class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0]=height[0];
        right[n-1]=height[n-1];
        for (int i = 1; i < n-1; i++)
            left[i] = max(left[i-1], height[i]);

        for (int i = n - 2; i >= 1; i--)
            right[i] = max(right[i+1], height[i]);

        for (int i = 1; i < n - 1; i++) {
            if (height[i] < right[i] and height[i] < left[i])
                water += min(left[i], right[i]) - height[i];
        }
        return water;
    }
};