#include "bitset.hpp"

// Default Constructor: N = 8, Data = all 0's.
Bitset::Bitset() {
    N = 8;
    // Calculate the size of the needed array length (integer division w/ rounding up)
    intmax_t arraySize = 1 + ((N - 1) / 8);
    data = new u_int8_t[arraySize];
    isGood = true;

    // Fill array
    for (int i = 0; i < N; i++) {
        reset(i);
    }
}

// Constructor with specified size: N = size, Data = all 0's.
Bitset::Bitset(intmax_t size) {
    N = size;
    // Calculate the size of the needed array length (integer division w/ rounding up)
    intmax_t arraySize = 1 + ((N - 1) / 8);
    data = new u_int8_t[arraySize];
    isGood = true;

    // Check if size is > 0
    if (size <= 0) {
        isGood = false;
    }

    // Fill array
    for (int i = 0; i < N; i++) {
        reset(i);
    }
}

// Constructor with specified string of 0's and 1's.
Bitset::Bitset(const std::string & value) {
    N = value.length();
    // Calculate the size of the needed array length (integer division w/ rounding up)
    intmax_t arraySize = 1 + ((N - 1) / 8);
    data = new u_int8_t[arraySize];
    isGood = true;

    // Set the data array
    for (intmax_t i = 0; i < N; i++)
    {
        if (value.at(i) == '1') {
            set(i);
        } else if (value.at(i) == '0') {
            reset(i);
        } else {
            isGood = false;
        }
    }
}

// Default Destructor
Bitset::~Bitset() {
    delete[] data;
}

// Accessor for size of bitset.
intmax_t Bitset::size() const {
    return N;
}

// Method to determine if bitset is valid.
bool Bitset::good() const {
    return isGood;
}

// Method to set a specific bit to a 1.
void Bitset::set(intmax_t index) {
    int arr = index / 8;
    int arrIndex = index - (arr * 8);

    // Ensure index is in range [0, N-1]
    if (index >= 0 && index < N) {
        // Set bit
        data[arr] |= 1UL << arrIndex;
    } else {
        isGood = false;
    }
}

// Method to set a specific bit to a 0.
void Bitset::reset(intmax_t index) {
    int arr = index / 8;
    int arrIndex = index - (arr * 8);

    // Ensure index is in range [0, N-1]
    if (index >= 0 && index < N) {
        // Reset bit
        data[arr] &= ~(1UL << arrIndex);
    } else {
        isGood = false;
    }
}

// Method to toggle a specific bit between 0 and 1.
void Bitset::toggle(intmax_t index) {
    int arr = index / 8;
    int arrIndex = index - (arr * 8);

    // Ensure index is in range [0, N-1]
    if (index >= 0 && index < N) {
        // Flip bit
        data[arr] ^= 1UL << arrIndex;
    } else {
        isGood = false;
    }
}

// Accessor to determine if a specific bit is a 1.
bool Bitset::test(intmax_t index) {
    int arr = index / 8;
    int arrIndex = index - (arr * 8);

    // Ensure index is in range [0, N-1]
    if (index >= 0 && index < N) {
        // Return true / false if data is a 1
        return ((data[arr] >> arrIndex) & 1U == 1);
    } else {
        // Invalidate bitset and return false
        isGood = false;
        return false;
    }
}

// Method to return string format of the bitset.
std::string Bitset::asString() const {
    // Define Result
    std::string result = "";

    // Create result string
    for (intmax_t i = 0; i < N; i++) {
        int arr = i / 8;
        int arrIndex = i - (arr * 8);

        if ((data[arr] >> arrIndex) & 1U == 1) {
            result.push_back('1');
        } else {
            result.push_back('0');
        }
    }

    // Return resulting string
    return result;
}
