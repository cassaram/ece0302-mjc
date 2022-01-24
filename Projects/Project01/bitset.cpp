#include "bitset.hpp"

// TODO
// Default Constructor: N = 8, Data = all 0's.
Bitset::Bitset() {
    // Define & set global variables
    N = 8;
    data = new bool[8];
    isGood = true;

    // Set data array
    for (unsigned i = 0; i < N; i++)
    {
        data[i] = false;
    }
}

// Constructor with specified size: N = size, Data = all 0's.
Bitset::Bitset(intmax_t size) {
    // Define & set global variables
    N = size;
    data = new bool[N];
    isGood = true;

    // Check if size is > 0
    if (size <= 0) {
        isGood = false;
    }

    // Set the data array
    for (unsigned i = 0; i < N; i++)
    {
        data[i] = false;
    }
}

// Constructor with specified string of 0's and 1's.
Bitset::Bitset(const std::string & value) {
    // Define & set global variables
    N = value.length();
    data = new bool[N];
    isGood = true;

    // Set the data array
    for (unsigned i = 0; i < N; i++)
    {
        if (value.at(i) == '0') {
            data[i] = false;
        } else if (value.at(i) == '1') {
            data[i] = true;
        } else {
            isGood = false;
        }
    }
}

// Default Destructor
Bitset::~Bitset() {
    delete N;
    delete[] data;
    delete isGood;
}

// Accessor for size of bitset.
intmax_t Bitset::size() {
    return N;
}

// Method to determine if bitset is valid.
bool Bitset::good() {
    return isGood;
}

// Method to set a specific bit to a 1.
void Bitset::set(intmax_t index) {
    // Ensure index is in range [0, N-1]
    if (index >= 0 && index < N) {
        // Set bit
        data[index] = true;
    } else {
        isGood = false;
    }
}

// Method to set a specific bit to a 0.
void Bitset::reset(intmax_t index) {
    // Ensure index is in range [0, N-1]
    if (index >= 0 && index < N) {
        // Reset bit
        data[index] = false;
    } else {
        isGood = false;
    }
}

// Method to toggle a specific bit between 0 and 1.
void Bitset::toggle(intmax_t index) {
    // Ensure index is in range [0, N-1]
    if (index >= 0 && index < N) {
        // Flip bit
        data[index] = !data[index];
    } else {
        isGood = false;
    }
}

// Accessor to determine if a specific bit is a 1.
bool Bitset::test(intmax_t index) {
    // Ensure index is in range [0, N-1]
    if (index >= 0 && index < N) {
        // Return true / false if data is a 1
        return data[index];
    } else {
        // Invalidate bitset and return false
        isGood = false;
        return false;
    }
}

// Method to return string format of the bitset.
std::string Bitset::asString() {
    // Define Result
    std::string result = "";

    // Create result string
    for (unsigned i = 0; i < N; i++) {
        if (data[i]) {
            // Set bit, add 1
            result.push_back('1');
        } else {
            // Unset bit, add 0
            result.push_back('0');
        }
    }

    // Return resulting string
    return result;
}
