class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int totalChalks=0;
        for(int it: chalk)
            totalChalks+=it;
        
        while(totalChalks<=k) k-=totalChalks;

        for(int i=0;i<chalk.size();i++){
            if(chalk[i]>k) return i;
            else k-=chalk[i];
        }
        return -1;
    }
};