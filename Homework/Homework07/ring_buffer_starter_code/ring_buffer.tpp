#include "ring_buffer.h"

#include <cassert>

template <typename T>
RingBuffer<T>::RingBuffer(std::size_t size)
{
    queueLength = size;
    data.reset(new T[queueLength]);
    front = 0;
    back = queueLength-1;
    count = 0;
}

template <typename T>
bool RingBuffer<T>::enqueue_front(const T& item) {
    // Ensure item can be added to queue
    if (count != queueLength) {
        // Move count 1 item forward
        front = (front - 1) % queueLength;
        // Insert item into queue
        data[front] = item;
        // Increment count
        ++count;
        // Success
        return true;
    }

    // Failure
    return false;
}

template <typename T>
bool RingBuffer<T>::enqueue_back(const T& item)
{
    if(count != queueLength){
        back = (back + 1) % queueLength;
        data[back] = item;
        ++count;
        return true;
    }

    return false;
}

template <typename T>
T RingBuffer<T>::dequeue_front()
{
    assert(count > 0);

    T value;

    value = data[front];
    front = (front +1) % queueLength;
    --count;

    return value;
}

template <typename T>
T RingBuffer<T>::dequeue_back(const T& item) {
    // Ensure queue has at least 1 element to dequeue
    assert(count > 0);

    // Variable with value to return
    T value;
    // Get item from queue
    value = data[back];
    // Remove item from queue
    back = (back - 1) % queueLength;
    --count;

    // Return item
    return value;
}

template <typename T>
long int RingBuffer<T>::getCount()
{
    return count;
}
