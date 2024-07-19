class Solution {
public:

    // TC: O(N+M) [N is the length of nums2 and M is the length of nums1]
    // SC: O(N) [due to the hashmap and stack used to store elements from nums2]

    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Hash map to store the next greater element for each element in nums2
        unordered_map<int, int> nextGreater;
        // Stack to keep track of elements for which we need to find the next
        // greater element
        stack<int> s;

        // Iterate through nums2 to fill the nextGreater map
        for (int num : nums2) {
            // While stack is not empty and the current element is greater than
            // the element at the top of the stack
            while (!s.empty() && s.top() < num) {
                // The current element is the next greater element for the
                // element at the top of the stack
                nextGreater[s.top()] = num;
                // Pop the top element from the stack
                s.pop();
            }
            // Push the current element onto the stack
            s.push(num);
        }

        // For elements that do not have a next greater element, set their next
        // greater element to -1
        while (!s.empty()) {
            nextGreater[s.top()] = -1;
            s.pop();
        }

        // Prepare the result for nums1
        vector<int> result;
        for (int num : nums1) {
            // Use the nextGreater map to find the next greater element for each
            // element in nums1
            result.push_back(nextGreater[num]);
        }

        return result;
    }
};
