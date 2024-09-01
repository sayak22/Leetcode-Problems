class Solution {
public:
    int findComplement(int num) {
        int ans = 0, i = 0; // i stores the position of the bit
        while (num) {
            if ((num & 1) == 0)
                ans += (1 << i); // we are only operating for ~0 = 1, because
                                 // adding 0 before anything is pointless
            i++;
            num >>= 1;
        }
        return ans;
    }
};