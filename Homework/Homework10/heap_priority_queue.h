
#ifndef _HEAP_PRIORITY_QUEUE_H_
#define _HEAP_PRIORITY_QUEUE_H_

#include "abstract_priority_queue.h"
#include "dynamic_array_list.h"

template <typename T>
class HeapPriorityQueue: public AbstractPriorityQueue<T>
{
public:

    // return true if the priority queue is empty
    bool isEmpty();

    // insert item into the queue
    void add(const T& item);

    // remove highest priority item from the queue
    void remove();

    // get the item with the highest priority from the queue
    T peek();

private:

    DynamicArrayList<T> lst;
};

template <typename T>
bool HeapPriorityQueue<T>::isEmpty()
{
    // Return list call
    return lst.isEmpty();
}

template <typename T>
void HeapPriorityQueue<T>::add(const T& item)
{
    // Perform insertion at end of list
    lst.insert(lst.getLength(), item);

    // Check for first element insertion
    if (lst.getLength() == 1) {
        // No reason to continue as its a 1-element heap
        return;
    }

    // Get variables to iterate through heap bottom-up
    std::size_t element = lst.getLength() - 1;
    std::size_t parent = (element - 1) / 2;

    // Iterate through heap array
    while ((element >= 1) && (lst.getEntry(parent) < item)) {
        // Replace current position with parent
        lst.setEntry(element, lst.getEntry(parent));
        lst.setEntry(parent, item);

        // Move to next parent
        element = parent;
        parent = (parent - 1) / 2;
    }
}

template <typename T>
void HeapPriorityQueue<T>::remove()
{
    // Replace root with last node and delete last element
    lst.setEntry(0, lst.getLength() - 1);
    lst.remove(lst.getLength() - 1);

    // Re-sort top-down
    std::size_t i = 0;
    while (i < lst.getLength()) {
        // Find children
        std::size_t left = 2 * i + 1;
        std::size_t right = 2 * i + 2;

        // Perform search
        // Find largest
        std::size_t largest = i;
        if ((left < lst.getLength()) && (lst.getEntry(left) > lst.getEntry(largest))) {
            largest = left;
        }
        if ((right < lst.getLength()) && (lst.getEntry(right) > lst.getEntry(largest))) {
            largest = right;
        }

        // Check if largest is i
        if (largest != i) {
            // Swap largest and i
            T item = lst.getEntry(i);
            lst.setEntry(i, lst.getEntry(largest));
            lst.setEntry(largest, item);

            // Increment i
            i = largest;
        } else {
            // Sorted
            break;
        }
    }
}

template <typename T>
T HeapPriorityQueue<T>::peek()
{
    // Return root at first index
    return lst.getEntry(0);
}


#endif // _HEAP_PRIORITY_QUEUE_H_
