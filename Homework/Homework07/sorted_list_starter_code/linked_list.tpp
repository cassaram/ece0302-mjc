#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
    firstNode = NULL;
    lastNode = NULL;
    length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    // Loop through list, deleting nodes
    Node<T>* next = firstNode;
    Node<T>* current = firstNode;
    while (length > 0) {
        current = next;
        next = current->getNext();
        delete current;
        length--;
    }

    // Remove pointers
    firstNode = NULL;
    lastNode = NULL;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
    // Copy linked-list length
    length = x.length;

    // Ensure list contains at least 1 good node
    if (x.firstNode == nullptr) {
        return;
    }

    // Setup iterative pointers
    Node<T>* current = x.firstNode;
    firstNode = NULL;
    lastNode = NULL;

    // Loop through
    while (current != NULL) {
        // Ensure we set up first node
        if (firstNode == NULL) {
            firstNode = new Node<T>(current->getItem(), NULL);
            lastNode = firstNode;
        } else {
            // Copy node to end of current list
            lastNode->setNext(new Node<T>(current->getItem(), NULL));
            lastNode = lastNode->getNext();
        }

        // Get next node to iterate over
        current = current->getNext();
    }
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
    // Copy first / last nodes of both lists
    Node<T>* x_first = x.firstNode;
    Node<T>* y_first = y.firstNode;
    Node<T>* x_last = x.lastNode;
    Node<T>* y_last = y.lastNode;

    // Set first / last nodes of both lists
    x.firstNode = y_first;
    x.lastNode = y_last;
    y.firstNode = x_first;
    y.lastNode = x_last;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
    // Copy linked-list length
    length = x.length;

    // Ensure list contains at least 1 good node
    if (x.firstNode == nullptr) {
        return *this;
    }

    // Setup iterative pointers
    Node<T>* current = x.firstNode;
    firstNode = NULL;
    lastNode = NULL;

    // Loop through
    while (current != NULL) {
        // Ensure we set up first node
        if (firstNode == NULL) {
            firstNode = new Node<T>(current->getItem(), NULL);
            lastNode = firstNode;
        } else {
            // Copy node to end of current list
            lastNode->setNext(new Node<T>(current->getItem(), NULL));
            lastNode = lastNode->getNext();
        }

        // Get next node to iterate over
        current = current->getNext();
    }

    // Return new list
    return *this;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    // Return if it is empty
    return (firstNode == NULL);
}

template <typename T>
std::size_t LinkedList<T>::getLength() const
{
    // Return length of list
    return length;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
    // Ensure position is in bounds
    if (position < 1 || position > length+1) {
        return false;
    }

    // Create node
    Node<T>* newNode = new Node<T>(item, NULL);

    // Special case for first element in new array
    if (position == 1 && length == 0) {
        firstNode = newNode;
        lastNode = newNode;
        length++;
        return true;
    }

    // Special case for last element
    if (position == length + 1) {
        lastNode->setNext(newNode);
        lastNode = newNode;
        length++;
        return true;
    }

    // Traverse array
    Node<T>* current = firstNode;
    for (std::size_t i = 1; i < position - 1; i++) {
        current = current->getNext();
    }

    // Insert new node
    Node<T>* next = current->getNext();
    newNode->setNext(next);
    current->setNext(newNode);

    // Update length
    length++;

    return true;
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
    // Ensure position is in bounds
    if (position < 1 || position > length+1) {
        return false;
    }

    // Special case for first element
    if (position == 1) {
        Node<T>* next = firstNode->getNext();
        delete firstNode;
        firstNode = next;
        length--;
        return true;
    }

    // Special case for last element
    if (position == length) {
        // Traverse List
        Node<T>* newLast = firstNode;
        for (std::size_t i = 1; i < position - 1; i++) {
            newLast = newLast->getNext();
        }

        // Set new last node
        delete lastNode;
        lastNode = newLast;

        length--;
        return true;
    }

    // Traverse array
    Node<T>* last = firstNode;
    for(std::size_t i = 1; i < position - 1; i++) {
        last = last->getNext();
    }

    // Set next node
    Node<T>* current = last->getNext();
    last->setNext(current->getNext());
    delete current;

    // Update length
    length--;

    return true;
}

template <typename T>
void LinkedList<T>::clear()
{
    // Loop through list, deleting nodes
    Node<T>* next = firstNode;
    Node<T>* current = firstNode;
    while (length > 0) {
        current = next;
        next = current->getNext();
        delete current;
        length--;
    }

    // Remove pointers
    firstNode = NULL;
    lastNode = NULL;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
    // Ensure position is in bounds
    if (position >= 1 && position <= length) {
        // Iterate to correct node
        Node<T>* current = firstNode;
        for (std::size_t i = 1; i < position; i++) {
            current = current->getNext();
        }

        // Return entry
        return current->getItem();
    }

    // Not found, return blank item
    return T();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
    // Ensure position is in bounds
    if (position >= 1 && position <= length) {
        // Iterate to correct node
        Node<T>* current = firstNode;
        for (std::size_t i = 1; i < position; i++) {
            current = current->getNext();
        }

        // Set item
        current->setItem(newValue);
    }
}
