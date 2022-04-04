#include "binary_search_tree.h"

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree()
{
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::BinarySearchTree(
    const BinarySearchTree<KeyType, ItemType>& rhs)
{
    root = 0;
    clone(rhs.root);
}

// this is an alternative implementation using a stack to simulate the recursion
template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::clone(Node<KeyType, ItemType>* rhs)
{
    Node<KeyType, ItemType>** lhs = &root;

    std::stack<stackvar<KeyType, ItemType>> s;

    stackvar<KeyType, ItemType> rootvar;
    rootvar.rhs = rhs;
    rootvar.lhs = lhs;
    s.push(rootvar);

    while (!s.empty()) {
        stackvar<KeyType, ItemType> currentvar = s.top();
        s.pop();

        Node<KeyType, ItemType>* curr_rhs = currentvar.rhs;
        Node<KeyType, ItemType>** curr_lhs = currentvar.lhs;

        if (curr_rhs == 0)
            continue;

        // allocate new node and copy contents
        Node<KeyType, ItemType>* temp = new Node<KeyType, ItemType>;
        temp->key = curr_rhs->key;
        temp->data = curr_rhs->data;
        temp->left = 0;
        temp->right = 0;
        *curr_lhs = temp;

        // push left subtree
        currentvar.rhs = curr_rhs->left;
        currentvar.lhs = &((*curr_lhs)->left);
        s.push(currentvar);

        // push right subtree
        currentvar.rhs = curr_rhs->right;
        currentvar.lhs = &((*curr_lhs)->right);
        s.push(currentvar);
    }
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::destroy()
{
    std::stack<Node<KeyType, ItemType>*> s;
    s.push(root);

    while (!s.empty()) {
        Node<KeyType, ItemType>* curr = s.top();
        s.pop();

        if (curr != 0) {
            s.push(curr->left);
            s.push(curr->right);
            delete curr;
        }
    }
    root = 0;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>& BinarySearchTree<KeyType, ItemType>::
operator=(const BinarySearchTree<KeyType, ItemType>& rhs)
{
    if (&rhs == this)
        return *this;

    destroy();

    root = 0;
    clone(rhs.root);

    return *this;
}

template <typename KeyType, typename ItemType>
BinarySearchTree<KeyType, ItemType>::~BinarySearchTree()
{
    destroy();
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::insert(
    const KeyType& key, const ItemType& item)
{
    // Create node from input
    Node<KeyType, ItemType>* insertNode;
    insertNode->key = key;
    insertNode->data = item;

    // Check if tree is empty
    if (isEmpty()) {
        // Insert node at root
        root = insertNode;
        insertNode = nullptr;

        return true;
    }

    // Search for insertion position
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);

    // Perform Insertion
    if (key < curr->key) {
        // Insert left
        curr->left = insertNode;
        insertNode = nullptr;

        return true;
    }

    if (key > curr->key) {
        // Insert right
        curr->right = insertNode;
        insertNode = nullptr;

        return true;
    }

    // General failure at this point (duplicate?)
    insertNode = nullptr;
    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::isEmpty()
{
    return (root == 0);
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::retrieve(
    const KeyType& key, ItemType& item)
{
    Node<KeyType, ItemType>* curr;
    Node<KeyType, ItemType>* curr_parent;
    search(key, curr, curr_parent);

    if (curr == 0)
        return false;

    if (curr->key == key) {
        item = curr->data;
        return true;
    }

    return false;
}

template <typename KeyType, typename ItemType>
bool BinarySearchTree<KeyType, ItemType>::remove(KeyType key)
{
    if (isEmpty()) {
        return false; // empty tree
    }

    // Search for item of key
    Node<KeyType, ItemType> *curr;
    Node<KeyType, ItemType> *curr_parent;
    search(key, curr, curr_parent);

    // case one thing in the tree
    if ((root->left == 0) && (root->right == 0)) {
        // Remove node
        delete root;
        root = nullptr;

        return true;
    }

    // case, found deleted item at leaf
    if ((curr->left == 0) && (curr->right == 0)) {
        // Remove linkage from parent
        if (curr_parent->left == curr) {
            curr_parent->left = nullptr;
        } else if (curr_parent->right == curr){
            curr_parent->right = nullptr;
        } else {
            // Something went seriously wrong
            return false;
        }

        // Remove node
        delete curr;
        curr = nullptr;

        return true;
    }

    // case, item to delete has only a right child
    if ((curr->left == 0) && (curr->right != 0)) {
        // Check where to insert child node(s) onto parent / root
        if (curr_parent->right == curr) {
            // Parent -> Current
            curr_parent->right = curr->right;
        } else if (curr_parent->left == curr) {
            // Current <- Parent
            curr_parent->left = curr->right;
        } else if (curr_parent == 0) {
            // Current is root
            root = curr->right;
        } else {
            // Something went seriously wrong
            return false;
        }

        // Remove node
        curr->right = nullptr;
        delete curr;
        curr = nullptr;

        return true;
    }

    // case, item to delete has only a left child
    if ((curr->left != 0) && (curr->right == 0)) {
        // Check where to insert child node(s) onto parent / root
        if (curr_parent->right == curr) {
            // Parent -> Current
            curr_parent->right = curr->left;
        } else if (curr_parent->left == curr) {
            // Current <- Parent
            curr_parent->left = curr->left;
        } else if (curr_parent == 0) {
            // Current is root
            root = curr->left;
        } else {
            // Something went seriously wrong
            return false;
        }

        // Remove node
        curr->left = nullptr;
        delete curr;
        curr = nullptr;

        return true;
    }

    // case, item to delete has two children
    if ((curr->left != 0) && (curr->right != 0)) {
        // Find successor by in-order
        Node<KeyType, ItemType> *succ;
        Node<KeyType, ItemType> *succ_parent;
        inorder(curr, succ, succ_parent)

        // Move successor to current's location
        // Check where to insert child node(s) onto parent / root
        if (curr_parent->right == curr) {
            // Parent -> Current
            curr_parent->right = succ;
        } else if (curr_parent->left == curr) {
            // Current <- Parent
            curr_parent->left = succ;
        } else if (curr_parent == 0) {
            // Current is root
            root = succ;
        } else {
            // Something went seriously wrong
            return false;
        }

        // Move subtrees
        succ->left = curr->left;
        succ->right = curr->right;

        // Remove current
        delete curr;
        curr = nullptr;

        return true;
    }

    return false; // default should never get here
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::inorder(Node<KeyType, ItemType>* curr,
    Node<KeyType, ItemType>*& in, Node<KeyType, ItemType>*& parent)
{
    // TODO
    // move right once
    curr = curr->right;

    // move left as far as possible
    // Check if we are as far left as possible
    if (curr->left == 0) {
        // Return with this node
        in = curr;
        return;
    } else {
        // Continue left via recursion
        inorder(curr->left, in, curr);
    }
}

template <typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::search(KeyType key,
    Node<KeyType, ItemType>*& curr, Node<KeyType, ItemType>*& parent)
{
    curr = root;
    parent = 0;

    if (isEmpty())
        return;

    while (true) {
        if (key == curr->key) {
            break;
        } else if (key < curr->key) {
            if (curr->left != 0) {
                parent = curr;
                curr = curr->left;
            } else
                break;
        } else {
            if (curr->right != 0) {
                parent = curr;
                curr = curr->right;
            } else
                break;
        }
    }
}

template<typename KeyType, typename ItemType>
void BinarySearchTree<KeyType, ItemType>::treeSort(ItemType arr[], int size) {
    // Function will use the array items as both key and value

    // Ensure tree is empty
    destroy();

    // Check for duplicates while converting array to tree
    // Check happens within insert function
    for (std::size_t i = 0; i < size; i++) {
        if (!insert(arr[i], arr[i])) {
            // Duplicate or failure to insert
            return;
        }
    }

    // Put items back into array via inorder
    for (std::size_t i = 0; i < size; i++) {
        // Find smallest node via inorder
        Node<KeyType, ItemType> *curr;
        Node<KeyType, ItemType> *curr_parent;
        inorder(root, curr, curr_parent);

        // Write node data to array
        arr[i] = curr->data;

        // Delete node
        remove(curr->key);

        // Cleanup iteration
        curr = nullptr;
        curr_parent = nullptr;
    }
}
