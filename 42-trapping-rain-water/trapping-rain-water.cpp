class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        vector<int> left(n, 0); // stores max height recorded to the left of the current element
        vector<int> right(n, 0);// stores max height recorded to the right of the current element
        //we donot need the end elements as they cannot store water (wall on only one side)
        left[0]=height[0]; //assigning this because for left[1] the max element to the left element be the height of that element
        right[n-1]=height[n-1]; // same reason as to why we assigned left[0] = height[0]


        for (int i = 1; i < n-1; i++)
            left[i] = max(left[i-1], height[i]);

        for (int i = n - 2; i >= 1; i--)
            right[i] = max(right[i+1], height[i]);

        for (int i = 1; i < n - 1; i++) {
            if (height[i] < right[i] and height[i] < left[i]) // that element can store water only if it has height less than the highest height to it's right and left
                water += min(left[i], right[i]) - height[i]; //water level will be till the minimum of the wall height to the right and left
        }
        return water;
    }
};