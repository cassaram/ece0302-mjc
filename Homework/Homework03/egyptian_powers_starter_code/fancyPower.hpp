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
	// Check if power is 0
	if (m == 0) {
		return 1;
	} else if (m == 1) {
		return n;
	} else if (m == 2) {
		return (n * n);
	} else {
		if (m % 2 == 0) {
			// Even Power
			return fancyPower(fancyPower(n, 2), (m/2));
		} else {
			// Odd Power
			return (n * fancyPower(fancyPower(n, 2), ((m-1)/2)));
		}
	}
	return 0;
}

#endif
