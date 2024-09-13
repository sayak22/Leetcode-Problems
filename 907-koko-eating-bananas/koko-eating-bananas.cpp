class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = INT_MIN;
        for (int pile : piles)
            maxPile = max(maxPile, pile);

        int l = 1, r = maxPile, ans = maxPile;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long int totalTime = 0;
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