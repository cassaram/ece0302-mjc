#include "dynamic_bag.hpp"

template<typename T>
DynamicBag<T>::DynamicBag() {
    size = 0;
    data = new T[size];
}


template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag& x){
    size = x.size;
    data = new T[size];
    for (std::size_t i = 0; i < size; i++) {
        data[i] = x.data[i];
    }
}

template<typename T>
DynamicBag<T>::~DynamicBag() {
    delete[] data;
}

template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T>& x)
{
    size = x.size;
    data = new T[size];
    for (std::size_t i = 0; i < size; i++) {
        data[i] = x.data[i];
    }

    return *this;
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
    size++;
    T* newData = new T[size];
    for (std::size_t i = 0; i < (size-1); i++)
    {
        newData[i] = data[i];
    }
    newData[size-1] = item;

    delete[] data;
    data = newData;

    return true;
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
    T *newData = new T[size];
    std::size_t removedIndex = -1;
    for (std::size_t i = 0; i < size; i++) {
        if (item == data[i]) {
            removedIndex = i;
            break;
        }
    }

    if (removedIndex == -1) {
        return false;
    }

    std::size_t j = 0;
    for (std::size_t i = 0; i < size; i++) {
        if (i != removedIndex) {
            newData[j] = data[i];
            j++;
        }
    }
    delete[] data;
    data = newData;
    size--;

    return true;
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
    if (size == 0) {
        return true;
    }
    return false;
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
    return size;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{
    for (std::size_t i = 0; i < size; i++) {
        if (item == data[i]) {
            return true;
        }
    }
    return false;
}

template<typename T>
void DynamicBag<T>::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
    std::size_t count = 0;
    for (std::size_t i = 0; i < size; i++) {
        if (data[i] == item) {
            count++;
        }
    }
    return count;
};
