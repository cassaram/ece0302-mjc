//  Adapated from Frank M. Carrano and Timothy M. Henry.

/** ADT Stack implementation.
    @file Stack.cpp */

#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

// TODO: Implement the constructor here
template<class ItemType>
Stack<ItemType>::Stack()
{
    currentSize = 0;
    headPtr = nullptr;
}  // end default constructor

// TODO: Implement the destructor here
template<class ItemType>
Stack<ItemType>::~Stack()
{
    // Clear stack and delete all items
    Stack<ItemType>::clear();
}  // end destructor

// TODO: Implement the isEmpty method here
template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
    return (currentSize == 0);
}  // end isEmpty

// TODO: Implement the size method here
template<class ItemType>
int Stack<ItemType>::size() const
{
    return currentSize;
}  // end size

// TODO: Implement the push method here
template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
    // Check if we have a head
    if (headPtr == nullptr) {
        // Don't have a head, make first node
        headPtr = new Node<ItemType>(newItem);

        // Increment stack size
        currentSize++;

        // Success, return true
        return true;
    }
    // Create new node containing item and push to front of stack
    headPtr = new Node<ItemType>(newItem, headPtr);

    // Increment size of stack
    currentSize++;

    // Success, return true
    return true;
}  // end push

// TODO: Implement the peek method here
template<class ItemType>
ItemType Stack<ItemType>::peek() const throw(logic_error)
{
    // Get item off top of stack
    ItemType returnItem = headPtr->getItem();
    return returnItem;
}  // end peek

// TODO: Implement the pop method here
template<class ItemType>
bool Stack<ItemType>::pop()
{
    // Ensure top item exists
    if (currentSize < 1 || headPtr == nullptr) {
        // Top item doesn't exist or is inaccessible
        // Exit with failure
        return false;
    }

    // Get first item off stack and its node
    Node<ItemType> *n = headPtr;
    ItemType item = headPtr->getItem();

    // Remove node from stack
    headPtr = n->getNext();

    // Decrement stack count
    currentSize--;

    // Clean-up memory from removed node
    delete n;

    // Success, return true
    return true;
}  // end pop

// TODO: Implement the clear method here
template<class ItemType>
void Stack<ItemType>::clear()
{
    // Delete all nodes in stack
    while (currentSize > 0) {
        // Get top node
        Node<ItemType> *n = headPtr;

        // Remove top node from stack
        headPtr = n->getNext();

        // Delete old top node from memory
        delete n;

        // Decrement stack size
        currentSize--;
    }
}  // end clear

