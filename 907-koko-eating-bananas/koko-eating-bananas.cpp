class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // int maxPile = INT_MIN;
        // for (int pile : piles)
        //     maxPile = max(maxPile, pile);

        int maxPile=*max_element(piles.begin(), piles.end());

        int l = 1, r = maxPile, ans = maxPile;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            long totalTime = 0;
            for (int pile : piles)
                totalTime += ceil((double)pile / mid);

            if (totalTime <= h) {
                r = mid - 1;
                ans = mid;
            } else
                l = mid + 1;
        }
        return ans;
    }
};