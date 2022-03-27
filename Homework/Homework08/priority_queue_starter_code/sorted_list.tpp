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
    std::size_t pos = getPosition(item);

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
    std::size_t result = 0;

    // Find position via linear search
    for (std::size_t i = 0; i < getLength(); i++) {
        // Update result
        result = i;
        // Determine if we are at position
        if (newValue > getEntry) {
            // At position, break
            break;
        }
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
