#include "frontier_queue.hpp"

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop() {
    // Ensure queue has an item
    if (empty()) {
        // Return empty state
        return State<T>(T(), 0, 0);
    }

    // Get item to return
    State<T> item = queue.at(0);

    // Remove item from queue
    // Move last item to front and delete last item
    queue[0] = queue.at(queue.size() - 1);
    queue.pop_back();

    // Swap item with largest child as much as possible
    std::size_t parent = 0;
    std::size_t leftChild;
    std::size_t rightChild;

    while (leftChild < queue.size()) {
        // Get child nodes
        leftChild = (2 * parent) + 1;
        rightChild = leftChild + 1;

        // Find smallest child
        std::size_t smallestChild = leftChild;
        if (rightChild < queue.size()) {
            if (queue.at(leftChild).getFCost() > queue.at(rightChild).getFCost()) {
                smallestChild = rightChild;
            }
        }

        // Check for swap
        if (queue.at(smallestChild).getFCost() < queue.at(parent).getFCost()) {
            // Swap parent and smallest child
            State<T> temp = queue.at(parent);
            queue[parent] = queue.at(smallestChild);
            queue[smallestChild] = temp;

            // Update parent for next loop
            parent = smallestChild;
        } else {
            // No swap needed, all elements in place, break loop
            break;
        }
    }

    // Return item at front
    return item;
}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur) {
    // Create state
    State<T> item(p, cost, heur);

    // Insert state to bottom of queue
    queue.push_back(item);

    // Move item forward if path cost is less
    std::size_t index = queue.size() - 1;
    std::size_t parent;

    while (index > 0) {
        // Find parent
        parent = (index - 1) / 2;

        // Check if parent object is of larger cost
        if (queue.at(parent).getFCost() > queue.at(index).getFCost()) {
            // Swap parent and child
            queue[index] = queue.at(parent);
            queue[parent] = item;

            // Increment variables for next loop
            index = parent;
        } else {
            // Element in place, break loop
            break;
        }
    }
}

template <typename T>
bool frontier_queue<T>::empty() {
    return queue.empty();
}

template <typename T>
bool frontier_queue<T>::contains(const T &p) {
    for (std::size_t i = 0; i < queue.size(); i++) {
        if (queue.at(i).getValue() == p) {
            return true;
        }
    }

    return false;
}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost) {
    // Find first item to replace with
    std::size_t index = -1;
    for (std::size_t i = 0; i < queue.size(); i++) {
        // Check if item is the same
        if (queue.at(i).getValue() == p) {
            // Update index and break
            index = i;
            break;
        }
    }

    // Ensure we found an item
    if (index == -1) {
        // No matching item found, return
        return;
    }

    // Check if cost is lower
    if (cost < queue.at(index).getPathCost()) {
        // Update path cost
        queue.at(index).updatePathCost(cost);
    }
}


