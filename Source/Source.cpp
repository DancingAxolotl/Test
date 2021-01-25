#include "Source.h"
#include <stdexcept>

int add(int a, int b) {
	int sum = 0;
	int carry = 0;
	for (int i = 0; i < sizeof(int) * 8; ++i) {
		sum = a ^ b;
		carry = (a & b) << 1;
		if (carry < 0) { // if we carry over into the negative bit, it's an overflow
			throw std::overflow_error("Addition overflow");
		}
		a = carry;
		b = sum;
	}

	return sum;
}

void find_largest_sum(uint32_t T, const std::vector<uint32_t>& I, std::vector<uint32_t>& M, uint32_t& S) {
	if (T == 0)
	{
		S = 0;
		return;
	}

	// Setup the sum table with basic values
	std::vector<std::vector<bool>> checks(I.size(), std::vector<bool>(T + 1));

	for (int i = 0; i < I.size(); i++) {
		checks[i][0] = true;
	}

	for (int s = 1; s <= T; s++) {
		checks[0][s] = I[0] == s;
	}

	// Build the sum table up to the first solution
	uint32_t i;
	for (i = 1; i < I.size() && !checks[i - 1][T]; ++i)
	{
		for (uint32_t s = 0; s <= T; ++s)
		{
			if (checks[i - 1][s]) 
			{
				checks[i][s] = true;
			}
			else if (s >= I[i]) 
			{
				checks[i][s] = checks[i - 1][s - I[i]];
			}
		}
	}

	uint32_t setItem = i - 1;
	S = T;
	if (!checks[setItem][T]) // We couldn't find an exact solution
	{
		// So find the largest solution
		uint32_t s = T - 1;
		setItem = 0;
		while (!checks[setItem][s]) {
			if (++setItem == I.size())
			{
				setItem = 0;
				--s;
			}
		}
		S = s;
	}

	// Collect the solution
	uint32_t sum = S;
	M.push_back(I[setItem]);
	sum -= I[setItem];
	while (sum != 0)
	{
		setItem = 0;
		while (!checks[setItem][sum]) {
			++setItem;
		}
		M.push_back(I[setItem]);
		sum -= I[setItem];
	}
}