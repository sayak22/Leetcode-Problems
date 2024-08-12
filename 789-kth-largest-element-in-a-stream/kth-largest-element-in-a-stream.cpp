class KthLargest {
    int num; // The value of 'k'
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap of size k+1

public:
    KthLargest(int k, vector<int>& nums) {
        num = k; // Initialize 'num' with the given value of 'k'

        // Populate the min-heap with the first k elements from 'nums'
        for (auto ele : nums) {
            pq.push(ele);
            if (pq.size() > k) {
                pq.pop(); // Maintain the heap size at k+1
            }
        }
    }

    int add(int val) {
        pq.push(val); // Add the new element to the min-heap
        if (pq.size() > num) {
            pq.pop(); // Remove the smallest element (maintain heap size at k+1)
        }
        return pq.top(); // Return the current kth largest element
    }
};
