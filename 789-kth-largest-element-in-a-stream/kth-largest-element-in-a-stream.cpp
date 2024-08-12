class KthLargest {
    int num; // The value of 'k' (the kth largest element we're interested in)
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap to maintain the k largest elements

public:
    KthLargest(int k, vector<int>& nums) {
        num = k; // Initialize 'num' with the given value of 'k'

        // Populate the min-heap with the first 'k' elements from 'nums'
        for (auto ele : nums) {
            pq.push(ele);
            if (pq.size() > k) {
                pq.pop(); // If the heap size exceeds 'k', remove the smallest element
            }
        }
    }

    int add(int val) {
        pq.push(val); // Add the new element to the min-heap
        if (pq.size() > num) {
            pq.pop(); // If the heap size exceeds 'k', remove the smallest element
        }
        return pq.top(); // Return the current kth largest element
    }
};
