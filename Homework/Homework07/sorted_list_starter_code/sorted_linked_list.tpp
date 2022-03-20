#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList(): LinkedList<T>()
{

}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> & x):
    LinkedList<T>(x)
{

}

template <typename T>
SortedLinkedList<T>& SortedLinkedList<T>::operator=(const SortedLinkedList<T>& x)
{
    LinkedList<T>::operator=(x);
    return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
    // base destructor gets called automatically
}

template <typename T>
bool SortedLinkedList<T>::isEmpty()
{
    return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength()
{
    return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T& item)
{
    // Inserts item using binary insertion sorting method

    // Get position
    std::size_t insertPos = getPosition(item);

    // Insert item at insertPos
    LinkedList<T>::insert(insertPos, item);
}

template <typename T>
void SortedLinkedList<T>::remove(const T& item)
{
    if(isEmpty()) throw std::range_error("empty list in remove");

    // Remove item at position (if it exists)
    std::size_t itemPos = getPosition(item) - 1;
    if (item == getEntry(itemPos)) {
        // Item exists, remove it
        LinkedList<T>::remove(itemPos);
    }
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
    if(isEmpty()) throw std::range_error("empty list in remove");

    // Ensure position is valid
    if (position < 0 || position >= LinkedList<T>::length) throw std::range_error("index out of bounds");

    // Remove item
    LinkedList<T>::remove(position);
}

template <typename T>
void SortedLinkedList<T>::clear()
{
    LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position)
{
    return LinkedList<T>::getEntry(position+1);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T& newValue)
{
    // Find position of item in array via binary search
    // Create variables
    std::size_t startPos = 0;
    std::size_t endPos = LinkedList<T>::length - 1;

    // Binary search loop to find position
    while (startPos < endPos) {
        // Get middle position
        std::size_t middle = (startPos + endPos) / 2;

        // Get which half of sub-array item is in
        if (newValue >= getEntry(middle)) {
            // Item is in upper half
            // Move start pos to middle
            startPos = middle + 1;
        } else {
            // Item is in lower half
            // Move end pos to middle
            endPos = middle;
        }
    }

    // Get position of newValue
    std::size_t insertPos;
    if (newValue < getEntry(startPos)) {
        insertPos = startPos;
    } else {
        insertPos = startPos + 1;
    }

    return insertPos;
}
