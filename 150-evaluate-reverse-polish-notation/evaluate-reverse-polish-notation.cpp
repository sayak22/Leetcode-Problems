class Solution {
public:

// TC:O(N)
    int evalRPN(vector<string>& tokens) {
        stack<int> stk; // Stack to store intermediate results
        for (string str : tokens) {
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                // As soon as a operand is encountered, remove the last 2 operands operate on them and push
                int val1 = stk.top(); stk.pop();
                int val2 = stk.top(); stk.pop();
                int result;
                if (str == "+") result = val2 + val1;
                else if (str == "-") result = val2 - val1;
                else if (str == "*") result = val2 * val1;
                else if (str == "/") result = val2 / val1;
                stk.push(result);
            } else 
                stk.push(stoi(str)); // Convert operand to integer and push
            
        }
        return stk.top(); // Final result
    }
};
