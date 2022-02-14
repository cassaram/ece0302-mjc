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
    // Dereference
    Node<T>* current = firstNode;
    Node<T>* next = NULL;

    while (current != NULL)
    {
        next = current->getNext();
        free(current);
        current = next;
    }
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
            firstNode = &(new Node<T>(current->getItem(), NULL));
            lastNode = firstNode;
        } else {
            // Copy node to end of current list
            tail->setNext(&(new Node<T>(current->getItem(), NULL)));
            tail = tail->getNext();
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
    y.firstNode = y_first;
    y.lastNode = y_last;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
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
            firstNode = &(new Node<T>(current->getItem(), NULL));
            lastNode = firstNode;
        } else {
            // Copy node to end of current list
            tail->setNext(&(new Node<T>(current->getItem(), NULL)));
            tail = tail->getNext();
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
    if (position < 1 || index > length) {
        return false;
    }

    // Update length
    length++;

    // Iterate to correct node
    Node<T>* current = firstNode;
    for (std::size_t i = 1; i < position; i++) {
        current = current->getNext();
    }

    // Insert new node
    current->setNext(&(new Node<T>(item, current->getNext())));

    return true;
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
    // Ensure position is in bounds
    if (position < 1 || index > length) {
        return false;
    }

    // Update length
    length--;

    // Case for removing first node
    if (position == 1) {
        firstNode = firstNode->getNext();
        return true;
    }

    // Iterate to correct node
    Node<T>* last = firstNode;
    Node<T>* current = firstNode->getNext();
    for (std::size_t i = 1; i < position; i++) {
        current = current->getNext();
    }

    // Remove current node
    last->setNext(current->getNext());

    return true;
}

template <typename T>
void LinkedList<T>::clear()
{
    // Dereference
    Node<T>* current = firstNode;
    Node<T>* next = NULL;

    while (current != NULL)
    {
        next = current->getNext();
        free(current);
        current = next;
    }

    // Update length
    length = 0;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
    // Ensure position is in bounds
    if (position >= 1 && index <= length) {
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
    if (position >= 1 && index <= length) {
        // Iterate to correct node
        Node<T>* current = firstNode;
        for (std::size_t i = 1; i < position; i++) {
            current = current->getNext();
        }

        // Set item
        current->setItem(newValue);
    }
}
