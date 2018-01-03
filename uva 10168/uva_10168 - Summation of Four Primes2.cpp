//============================================================================
// Name        : uva_10168.cpp
// Author      : Moaz Rashad
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
using namespace std;
#define SZ 10000000

vector<int> getPrimes() {
	vector<bool> primes(SZ + 1, true);
	primes[0] = false, primes[1] = false;

	vector<int> primeNumbers(SZ + 1, 0);
	primeNumbers[0] = 0, primeNumbers[1] = 1, primeNumbers[2] = 2;

	for (int i = 4; i <= SZ; i += 2) {
		primes[i] = false;
	}

	for (int i = 3; i <= SZ; i += 2) {
		if (primes[i]) {
			primeNumbers[i] = i;
			for (int j = i + i; j <= SZ; j += i) {
				primes[j] = false;
			}
		}
	}

	int previousPrime = 3;
	for(int i = 4;i <= SZ;i++){
		if(primeNumbers[i] == 0)
			primeNumbers[i] = previousPrime;
		else
			previousPrime  = primeNumbers[i];
	}
	return primeNumbers;
}

int main() {

	vector<int> primes = getPrimes();
	int n;
	while (cin >> n) {
		if (n < 8) {
			cout << "Impossible." << endl;
			continue;
		}

		for(int i = 3 ; i >= 0 ;i--){
			int lastPrime = primes[n-(i*2)];
			cout << lastPrime <<" ";
			n-=lastPrime;
		}
		cout << endl;
	}

	return 0;
}
