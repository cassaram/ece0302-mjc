#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList() {
    // Initialize empty dynamic array
    length = 0;
    array = nullptr;
}

template <typename T>
ArrayList<T>::~ArrayList() {
    // Delete array
    delete[] array;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList & rhs) {
    // Copy length & initiate array
    length = rhs.length;
    array = new T[length];

    // Copy array elements
    for (std::size_t i = 0; i < length; i++)
    {
        array[i] = rhs.array[i];
    }
}

template <typename T>
ArrayList<T> & ArrayList<T>::operator=(const ArrayList & rhs){
    // Copy length & initiate array
    length = rhs.length;
    array = new T[length];

    // Copy array elements
    for (std::size_t i = 0; i < length; i++)
    {
        array[i] = rhs.array[i];
    }

    return *this;
}

template <typename T>
bool ArrayList<T>::isEmpty() const{
    // Return if array is empty
    return (length == 0);
}

template <typename T>
std::size_t ArrayList<T>::getLength() const{
    // Return length
    return length;
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
    // Calculate index to insert to
    std::size_t index = position - 1;

    // Check if inserted index is out of bounds
    if (index < 0 || index > length) {
        return false;
    };

    // Increment length and create new array
    length++;
    T* newArray = new T[length];

    // Copy existing elements from old array to new array, replacing element at position with item
    std::size_t j = 0;
    for (std::size_t i = 0; i < length; i++) {
        if (i == index) {
            // Replace item
            newArray[i] = item;
        } else {
            // Copy item
            newArray[i] = array[j];
            j++;
        }
    }

    // Replace array with new array
    delete[] array;
    array = newArray;

    return true;
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position) {
    // Calculate index to remove
    std::size_t index = position - 1;

    // Check if inserted index is out of bounds
    if (index < 0 || index > length) {
        return false;
    };

    // Decrement length and create new array
    length--;
    T* newArray = new T[length];

    // Copy existing elements from old array to new array, without element at position
    std::size_t j = 0;
    for (std::size_t i = 0; i <= length; i++) {
        if (i == index) {
            // Skip item
        } else {
            // Copy item
            newArray[j] = array[i];
            j++;
        }
    }

    // Replace array with new array
    delete[] array;
    array = newArray;

    return true;
}

template <typename T>
void ArrayList<T>::clear() {
    // Clear all items from array
    length = 0;
    delete[] array;
    array = nullptr;
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
    // Return item at index
    return array[position - 1];
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {
    // Calculate index to insert to
    std::size_t index = position - 1;

    // Check if inserted index is out of bounds
    if (index < 0 || index >= length) {
        return;
    };

    // Create new array
    T* newArray = new T[length];

    // Copy existing elements from old array to new array, replacing element at position with newValue
    for (std::size_t i = 0; i < length; i++) {
        if (i == index) {
            // Replace item
            newArray[i] = newValue;
        } else {
            // Copy item
            newArray[i] = array[i];
        }
    }

    // Replace array with new array
    delete[] array;
    array = newArray;
}
