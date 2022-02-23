#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

uint32_t reverseBits(uint32_t n) {
	uint32_t reversed = 0, i = 0;

	while (n != 0) {
		if (n % 2 != 0) {
			reversed += pow(2, (31 - i));
		}

		n /=2;
		i++;
	}

	return reversed;
}

uint32_t reverseBitsAlt(uint32_t n) {
	uint32_t reversed = 0;

	for (int i = 0; i < 32; ++i) {
		int bit = (n >> i) & 1;

		reversed |= (bit << (31 - i));
	}

	return reversed;
}

int main () {
	vector<uint32_t> testCases = {
		2,
		4294967293,
		43261596
	};

	for (auto test : testCases) {
		cout << reverseBitsAlt(test) << endl;
	}
	
	return 0;
}