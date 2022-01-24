#ifndef BITSET_HPP
#define BITSET_HPP
#include <string>

class Bitset{
public:

    // Default Constructor: N = 8, Data = all 0's.
    Bitset();

    // Constructor with specified size: N = size, Data = all 0's.
    Bitset(intmax_t size);

    // Constructor with specified string of 0's and 1's.
    Bitset(const std::string & value);

    // Default Destructor
    ~Bitset();

    Bitset(const Bitset & ) = delete;
    Bitset & operator=(const Bitset &) = delete;

    // Accessor for size of bitset.
    intmax_t size() const;

    // Method to determine if bitset is valid.
    bool good() const;

    // Method to set a specific bit to a 1.
    void set(intmax_t index);

    // Method to set a specific bit to a 0.
    void reset(intmax_t index);

    // Method to toggle a specific bit between 0 and 1.
    void toggle(intmax_t index);

    // Accessor to determine if a specific bit is a 1.
    bool test(intmax_t index);

    // Method to return string format of the bitset.
    std::string asString() const;

private:
    intmax_t N;  // Var to store the size of the bitset
    bool isGood; // Var to store if the bitset is valid
    bool *data;  // Pointer to store the data of the bitset as an array
};

#endif
