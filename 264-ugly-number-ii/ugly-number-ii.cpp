class Solution {
public:
    int nthUglyNumber(int n) {
        // Create a min heap to store potential ugly numbers.
        // We'll use a min heap so that we always extract the smallest element.
        priority_queue<long long, vector<long long>, greater<long long>> min_heap;

        // Create a set to keep track of all encountered ugly numbers.
        unordered_set<long long> ugly_set;

        // Start with the first ugly number (which is 1).
        min_heap.push(1);
        ugly_set.insert(1);

        // While we haven't found the nth ugly number:
        while (n > 1) {
            // Extract the smallest element from the heap.
            long long x = min_heap.top();
            min_heap.pop();

            // Check if 2*x, 3*x, and 5*x are not already in the set.
            // If not, add them to the set and push them onto the heap.
            if (ugly_set.find(2 * x) == ugly_set.end()) {
                min_heap.push(2 * x);
                ugly_set.insert(2 * x);
            }
            if (ugly_set.find(3 * x) == ugly_set.end()) {
                min_heap.push(3 * x);
                ugly_set.insert(3 * x);
            }
            if (ugly_set.find(5 * x) == ugly_set.end()) {
                min_heap.push(5 * x);
                ugly_set.insert(5 * x);
            }

            // Decrement n.
            n--;
        }

        // The last element remaining in the heap is our nth ugly number.
        return min_heap.top();
    }
};
