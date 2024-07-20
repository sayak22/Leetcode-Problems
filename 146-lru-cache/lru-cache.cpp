class LRUCache {
private:
    // Define a Node structure to represent key-value pairs
    struct Node {
        int key;
        int value;
        Node(int k, int v) : key(k), value(v) {}
    };

    const int capacity;  // Maximum capacity of the cache
    list<Node> cache;  // Doubly-linked list for the cache
    unordered_map<int, list<Node>::iterator> keyToIterator;  // Map key to its iterator

public:
    LRUCache(int cap) : capacity(cap) {
        // Initialize the cache with the specified capacity
    }

    int get(int key) {
        const auto it = keyToIterator.find(key);
        if (it == keyToIterator.end())
            return -1;  // Key not found in the cache

        // Move the accessed node to the front (most recently used)
        cache.splice(cache.begin(), cache, it->second);
        return it->second->value;
    }

    void put(int key, int value) {
        const auto it = keyToIterator.find(key);
        if (it != keyToIterator.end()) {
            // Update existing node and move it to the front
            it->second->value = value;
            cache.splice(cache.begin(), cache, it->second);
        } else {
            if (cache.size() == capacity) {
                // Remove the least recently used node (from the back)
                keyToIterator.erase(cache.back().key);
                cache.pop_back();
            }
            // Add the new node to the front
            cache.emplace_front(key, value);
            keyToIterator[key] = cache.begin();
        }
    }
};
