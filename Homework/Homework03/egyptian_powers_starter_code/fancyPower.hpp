#ifndef FANCYPOWER_HPP
#define FANCYPOWER_HPP

/**
 * @brief Function to calculate a power via Egyptian Powers
 *
 * @param n Base
 * @param m Exponent
 * @return int Result of power operation
 */
int fancyPower(int n, int m)
{
	// Check if power is 1
	if (m == 1) {
		return n;
	} else {
		if (m % 2 == 0) {
			// Even Power
			return fancyPower(n*n, n/2);
		} else {
			// Odd Power
			return fancyPower(n*n, (n-1)/2);
		}
	}
	return 0;
}

#endif
