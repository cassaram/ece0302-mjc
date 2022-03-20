#include "dynamic_array_list.h"

#include <algorithm>
#include <stdexcept>

#include <iostream>

#define DEFAULT_CAPACITY 10

template <typename T>
DynamicArrayList<T>::DynamicArrayList()
{
    capacity = DEFAULT_CAPACITY;
    size = 0;
    data = new T[capacity];
}

template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x)
{
    // Copy capacity and size
    capacity = x.capacity;
    size = x.size;

    // Create array
    data = new T[capacity];

    // Copy data
    for (std::size_t i = 0; i < size; i++) {
        data[i] = x.data[i];
    }
}

template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
    std::clog << "DynamicArrayList Destructor called." << std::endl;

    // Delete array
    delete[] data;
}

template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(DynamicArrayList<T> x)
{
    // Copy capacity and size
    capacity = x.capacity;
    size = x.size;

    // Create array
    data = new T[capacity];

    // Copy data
    for (std::size_t i = 0; i < size; i++) {
        data[i] = x.data[i];
    }
    return *this;
}

template <typename T>
void DynamicArrayList<T>::swap(DynamicArrayList<T>& y)
{
    // Copy varaibles off other object
    std::size_t newCapacity = y.capacity;
    std::size_t newSize = y.size;
    T* newData = &y.data;

    // Write data to other object
    y.capacity = capacity;
    y.size = size;
    y.data = data;

    // Write data to this object
    capacity = newCapacity;
    size = newSize;
    data = newData;
}

template <typename T>
bool DynamicArrayList<T>::isEmpty()
{
    return (size == 0);
}

template <typename T>
std::size_t DynamicArrayList<T>::getLength()
{
    return size;
}

template <typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{
    // Ensure position is valid
    if (position < 0 || position > size) {
        return;
    }

    // Increment size
    size++;

    // Ensure new size fits in capacity, otherwise increase capacity
    if (size > capacity) {
        // Does not fit in current capacity
        // Double capacity
        capacity = 2*capacity;

        // Create new array with larger capacity
        T* newData = new T[capacity];

        // Copy data into new array (except last element)
        for (std::size_t i = 0; i < size-1; i++) {
            newData[i] = data[i];
        }

        // Migrate to new array
        T* oldData = data;
        data = newData;
        delete[] oldData;
        delete oldData;
    }

    // Move all items back 1 index
    for (std::size_t i = size; i > position; i--) {
        data[i] = data[i-1];
    }

    // Insert new item
    data[position] = item;
}

template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
    // Ensure index is in bounds
    if (position < 0 || position >= size) {
        return;
    }

    // Decrement size
    size--;

    // Copy all items down 1 index after positon
    for (std::size_t i = position; i < size; i++) {
        data[i] = data[i+1];
    }
}

template <typename T>
void DynamicArrayList<T>::clear()
{
    // Delete array
    delete[] data;

    // Reset size & capacity
    size = 0;
    capacity = DEFAULT_CAPACITY;

    // Create new array
    data = new T[capacity];
}

template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position)
{
    // Ensure position is within range
    if (position < 0 || position >= size) {
        return T();
    }

    // Return item
    return data[position];
}

template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
    // Ensure position is within range
    if (position < 0 || position >= size) {
        return;
    }

    // Set position
    data[position] = newValue;
}
