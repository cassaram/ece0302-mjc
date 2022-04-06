#include "deque.hpp"

template <typename T>
Deque<T>::Deque() {
    // Empty
}

template <typename T>
Deque<T>::Deque(const Deque &other) {
    // Copy queue
    list = other.list;
}

template <typename T>
Deque<T>::~Deque() {
    // Clear items from list
    list.~LinkedList();
}

template <typename T>
Deque<T> &Deque<T>::operator=(const Deque<T> &other){
    // Copy queue
    list = other.list;

    // Return reference
    return *this;
}

template <typename T>
bool Deque<T>::isEmpty() const {
    // Return if deque is empty
    return list.isEmpty();
}

template <typename T>
void Deque<T>::pushFront(const T& item) {
    // Front is at index 1 due to linkedlists' 1-based indexing
    // Perform insertion
    list.insert(1, item);
}

template <typename T>
void Deque<T>::popFront() {
    // Remove item at first index using 1-based indexing
    list.remove(1);
}

template <typename T>
T Deque<T>::front() const {
    // Return item at index 1
    return list.getEntry(1);
}

template <typename T>
void Deque<T>::pushBack(const T& item) {
    // Get length
    std::size_t length = list.getLength();
    // Append item at length+1 (1 based index)
    list.insert(length+1, item);
}

template <typename T>
void Deque<T>::popBack() {
    // Get length
    std::size_t length = list.getLength();
    // Remove last item at length (1 based index)
    list.remove(length);
}

template <typename T>
T Deque<T>::back() const {
    // Get length
    std::size_t length = list.getLength();
    // Return last element at length (1 based index)
    return list.getEntry(length);
}
