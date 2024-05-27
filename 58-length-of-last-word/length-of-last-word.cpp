class Solution {
public:
    int lengthOfLastWord(string s) {
        // int n = s.length() - 1;
        // // eliminating all space at the end to get to the last character of the last word
        // while(s[n] == ' ')
        //     n--;
        // int ans = 0;
        // //counting the number of letters in the word, i.e, untill the current character is a space, we count the no. of characters which is = the length of the last word.
        // while(n >= 0 && s[n] != ' ') {
        //     n--;
        //     ans++;
        // }
        // return ans;

        int n=s.length(), count=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==' ') continue;
            else{
                while((i<n &&i>=0) && s[i]!=' '){
                    count++;
                    i--;
                }
                return count;
            }
        }
        return 0;
    }
};