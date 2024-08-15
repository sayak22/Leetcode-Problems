class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int fiveChange = 0, tenChange = 0; // at the start we don't have any change
        for (int x : bills) {
            if (x == 5)
                fiveChange++;
            else if (x == 10) {
                if (fiveChange > 0) {
                    fiveChange--; // we are accepting a 10 and giving a 5
                    tenChange++;
                } else
                    return false;
            } else if (x == 20) {
                if (fiveChange > 0 and tenChange > 0) {
                    fiveChange--; // we need not keep track of the 20 as it is not a change.
                    tenChange--;
                } else if (fiveChange > 2) {
                    fiveChange -= 3;
                } else
                    return false;
            }
        }
        return true;
    }
};