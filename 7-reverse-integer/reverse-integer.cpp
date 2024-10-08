class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            // checking the overflow/underflow before multiplying ans by 10
            if (ans > INT_MAX / 10 or ans < INT_MIN / 10)
                return 0;
            
            ans = ans * 10 + (x % 10);
            x /= 10;
        }
        return ans;
    }
};