
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

    // Get variables to iterate through heap bottom-up
    std::size_t element = lst.getLength() + 1;
    std::size_t parent = (element - 1) / 2;

    // Iterate through heap array
    while ((parent >= 1) && (lst.getEntry(parent) < item)) {
        // Replace current position with parent
        lst.setEntry(element, lst.getEntry(parent));

        // Move to next parent
        element = parent;
        parent = (parent - 1) / 2;
    }
    // Insert element
    lst.setEntry(element, item);
}

template <typename T>
void HeapPriorityQueue<T>::remove()
{
    // Remove item
    lst.remove(0);
}

template <typename T>
T HeapPriorityQueue<T>::peek()
{
    // Return root at first index
    return lst.getEntry(0);
}


#endif // _HEAP_PRIORITY_QUEUE_H_
