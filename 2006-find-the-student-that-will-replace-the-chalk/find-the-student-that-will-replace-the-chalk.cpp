class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int totalChalksReqd = 0;

        // finding total chalks required for the entire class.
        for (int it : chalk)
            totalChalksReqd += it;

        // finding out the remainder of chalks left after doing multiple rounds
        // of using 'totalChalksReqd' by the entire class
        k %= totalChalksReqd;

        // now finding which student will fall short of chalks to write
        for (int i = 0; i < chalk.size(); i++) {
            if (chalk[i] > k)
                return i;
            else
                k -= chalk[i];
        }

        return -1;
    }
};