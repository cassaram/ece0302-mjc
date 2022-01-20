#include "bag.hpp"

// empty implementation                                                                                                     

template <typename T> Bag<T>::Bag() {
    items = std::vector<T>();
}

template <typename T> Bag<T>::~Bag() {
    // Deletes items by swapping them with an empty vector with no memory initialized
    std::vector<T>().swap(items);
}

template <typename T> std::size_t Bag<T>::getCurrentSize() const { 
    // Return quantity of elements
    return items.size(); 
}

template <typename T> bool Bag<T>::isEmpty() const { 
    // Return if the quantity of elements is 0
    return (getCurrentSize() == 0); 
}

template <typename T> bool Bag<T>::add(const T& entry) { 
    // Add item to end of vector
    items.push_back(entry); 
    // Success is if the last item is the same as the item we just added
    return (items.at(getCurrentSize()-1) == entry);
}

template <typename T> bool Bag<T>::remove(const T& entry) { 
    // Loop through all items
    for (int i = 0; i < getCurrentSize(); i++) {
        // Check if current item is the same as our entry
        if (items.at(i) == entry) {
            // Remove item and exit loop with true success
            items.erase(items.begin()+i);
            return true;
        }
    }
    // Item not found, return false
    return false;
}

template <typename T> void Bag<T>::clear() {
    // Clear all elements from the items vector (does not free memory)
    items.clear();
}

template <typename T> std::size_t Bag<T>::getFrequencyOf(const T& entry) const { 
    // Variable to store count of items found
    int count = 0;
    // Iterate through all items
    for(int i = 0; i < getCurrentSize(); i++) {
        // Check if item is the same as our specified item
        if (items.at(i) == entry) {
            // Increment count of found items
            count++;
        }
    }
    // Return number of found items
    return count;
}

template <typename T> bool Bag<T>::contains(const T& entry) const { 
    // Iterate through all items
    for (int i = 0; i < getCurrentSize(); i++) {
        // Check if item is the same as the specified item
        if (items.at(i) == entry) {
            // Item is in vector, exit and return true
            return true;
        }
    }
    // Item is not in vector, return false
    return false;
}

