#include "limited_size_bag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() {
    size = 0;
    data = new T[size];
}


template<typename T>
LimitedSizeBag<T>::LimitedSizeBag(const LimitedSizeBag& x){
    if (x.size > MAXSIZE) {
        size = MAXSIZE;
    } else {
        size = x.size;
    }
    data = new T[size];
    for (std::size_t i = 0; i < size; i++) {
        data[i] = x.data[i];
    }
}

template<typename T>
LimitedSizeBag<T>::~LimitedSizeBag(){
    delete[] data;
}

template<typename T>
LimitedSizeBag<T>& LimitedSizeBag<T>::operator=(LimitedSizeBag<T>& x)
{
    if (x.size > MAXSIZE) {
        size = MAXSIZE;
    } else {
        size = x.size;
    }
    data = new T[size];
    for (std::size_t i = 0; i < size; i++) {
        data[i] = x.data[i];
    }

    return *this;
}

template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
    if (size+1 > MAXSIZE) {
        return false;
    }
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
bool LimitedSizeBag<T>::remove(const T& item)
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
bool LimitedSizeBag<T>::isEmpty() const
{
    if (size == 0) {
        return true;
    }
    return false;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return size;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{
    for (std::size_t i = 0; i < size; i++) {
        if (item == data[i]) {
            return true;
        }
    }
    return false;
}

template<typename T>
void LimitedSizeBag<T>::clear(){
    delete[] data;
    data = nullptr;
    size = 0;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
    std::size_t count = 0;
    for (std::size_t i = 0; i < size; i++) {
        if (data[i] == item) {
            count++;
        }
    }
    return count;
};
