class Solution {
public:
    string decodeString(string s) {
        
        stack<string> str;
        stack<int> nums;

        int curCount=0;
        string curString="";

        for(int i=0; i<s.size();i++){
            if(isdigit(s[i]))
                curCount = curCount*10 + (s[i]-'0');
            
            else if(isalpha(s[i]))
                curString += s[i];
            
            else if(s[i]=='['){
                nums.push(curCount);
                str.push(curString);
                curCount=0;
                curString="";
            }

            else if(s[i]==']'){
                int repeat = nums.top();
                nums.pop();

                string temp=curString;
                
                for(int i=1;i<repeat;i++){
                    curString+=temp;
                }

                if(!str.empty()){
                    curString = str.top() + curString;
                    str.pop();
                }
            }
        }
            return curString;
    }
};