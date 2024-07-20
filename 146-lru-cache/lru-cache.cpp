class LRUCache {
private:
    // Define a Node structure for the doubly-linked list
    struct Node {
        int key;
        int value;
        shared_ptr<Node> prev;
        shared_ptr<Node> next;
        Node(int key, int value) : key(key), value(value) {}
    };

    const int capacity;  // Maximum capacity of the cache
    unordered_map<int, shared_ptr<Node>> keyToNode;  // Map key to its corresponding node
    shared_ptr<Node> head = make_shared<Node>(-1, -1);  // Dummy head node
    shared_ptr<Node> tail = make_shared<Node>(-1, -1);  // Dummy tail node

    // Helper function to join two nodes in the doubly-linked list
    void join(shared_ptr<Node> node1, shared_ptr<Node> node2) {
        node1->next = node2;
        node2->prev = node1;
    }

    // Move a node to the front (most recently used)
    void moveToHead(shared_ptr<Node> node) {
        join(node, head->next);
        join(head, node);
    }

    // Remove a node from the list
    void remove(shared_ptr<Node> node) {
        join(node->prev, node->next);
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        join(head, tail);  // Initialize the doubly-linked list
    }

    int get(int key) {
        const auto it = keyToNode.find(key);
        if (it == keyToNode.cend())
            return -1;

        shared_ptr<Node> node = it->second;
        remove(node);
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (const auto it = keyToNode.find(key); it != keyToNode.cend()) {
            shared_ptr<Node> node = it->second;
            node->value = value;
            remove(node);
            moveToHead(node);
            return;
        }

        if (keyToNode.size() == capacity) {
            shared_ptr<Node> lastNode = tail->prev;
            keyToNode.erase(lastNode->key);
            remove(lastNode);
        }

        moveToHead(make_shared<Node>(key, value));
        keyToNode[key] = head->next;
    }
};
