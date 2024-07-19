class Solution {
public:
// TC: O(N) [vector traversal] SC:O(N) [when all right facing asteroids present (worst case)]
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> asteroidStack; // Stack to store surviving asteroids

        for (int asteroid : asteroids) {
            if (asteroid > 0) {
                // Right-moving asteroid, just push onto the stack
                asteroidStack.push(asteroid);
            } else {
                // Left-moving asteroid
                while (!asteroidStack.empty() && asteroidStack.top() > 0 &&
                       abs(asteroidStack.top()) < abs(asteroid)) {
                    // Collide with right-moving asteroid
                    asteroidStack.pop();
                }
                if (asteroidStack.empty() || asteroidStack.top() < 0) {
                    // Either stack is empty or top asteroid is left-moving
                    asteroidStack.push(asteroid);
                } else if (asteroidStack.top() == -asteroid) {
                    // Equal-sized asteroids collide and get destroyed
                    asteroidStack.pop();
                }
            }
        }

        // Convert stack to vector (in reverse order)
        vector<int> result(asteroidStack.size());
        for (int i = asteroidStack.size() - 1; i >= 0; --i) {
            result[i] = asteroidStack.top();
            asteroidStack.pop();
        }

        return result;
    }
};
