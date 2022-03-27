#include "sorted_list.h"

template <typename T, typename L>
SortedList<T, L>::SortedList()
{
    // nothing to do, plist gets created on the stack
}

template <typename T, typename L>
SortedList<T, L>::SortedList(const SortedList<T, L> & x)
{
    plist = x.plist; // use copy assignment to implement copy construction
}

template <typename T, typename L>
SortedList<T, L>& SortedList<T, L>::operator=(const SortedList<T, L>& x)
{
    plist = x.plist;
    return *this;
}

template <typename T, typename L>
SortedList<T, L>::~SortedList()
{
    // plist destructor gets called automatically
}

template <typename T, typename L>
bool SortedList<T, L>::isEmpty()
{
    return plist.isEmpty();
}

template <typename T, typename L>
std::size_t SortedList<T, L>::getLength()
{
    return plist.getLength();
}

template <typename T, typename L>
void SortedList<T, L>::insert(const T& item)
{
    // Find position to insert to
    long int pos = getPosition(item);

    // Find abs of pos
    if (pos < 0) {
        pos = pos * -1;
    }

    // Perform insertion
    plist.insert(pos, item);
}

template <typename T, typename L>
void SortedList<T, L>::remove(const T& item)
{
    // Find position of item
    std::size_t pos = getPosition(item);

    // Ensure item exists
    if (pos < 0) {
        // Item does not exist, return
        return;
    }

    // Remove item
    removeAt(pos);
}

template <typename T, typename L>
void SortedList<T, L>::removeAt(std::size_t position)
{
    plist.remove(position);
}

template <typename T, typename L>
void SortedList<T, L>::clear()
{
    plist.clear();
}

template <typename T, typename L>
T SortedList<T, L>::getEntry(std::size_t position)
{
    return plist.getEntry(position);
}

template <typename T, typename L>
long int SortedList<T, L>::getPosition(const T& newValue)
{
    // Determine result variable
    long int result = 0;

    // Case for empty list
    if (getLength() == 0) {
        return 0;
    }

    // Find position via binary search
    long int left = 0;
    long int right = getLength() - 1;
    long int middle;
    // Perform binary search
    while (left <= right) {
        // Find middle
        middle = (left + right) / 2;
        // Check if we found value
        if (getEntry(middle) == newValue) {
            // Found value, exit search
            left = middle;
            break;
        } else if (getEntry(middle) > newValue) {
            // In lower half
            right = middle - 1;
        } else {
            // In upper half
            left = middle + 1;
        }
    }

    result = left;

    // Ensure result is in bounds
    if (getLength() <= result) {
        return (getLength() * -1);
    }

    // Determine if we found the item
    if (getEntry(result) == newValue) {
        // Item is good
        return result;
    } else {
        // Item would be inserted here, negate
        return (result * -1);
    }
}
