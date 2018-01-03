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

	vector<int> primeNumbers;
	primeNumbers.push_back(2);

	for (int i = 4; i <= SZ; i += 2) {
		primes[i] = false;
	}

	for (int i = 3; i <= SZ; i += 2) {
		if (primes[i]) {
			primeNumbers.push_back(i);
			for (int j = i + i; j <= SZ; j += i) {
				primes[j] = false;
			}
		}
	}
	return primeNumbers;
}

int getLastPrime(int n,vector<int> primes,int subtract ){
	vector<int>::iterator low = lower_bound(primes.begin(), primes.end(),
			(n - subtract));
	bool checkLastPrime = false;
	if (primes[low - primes.begin()] == (n - subtract))
		checkLastPrime = true;

	return primes[low - primes.begin() - (!checkLastPrime)];
}

int main() {

	vector<int> primes = getPrimes();
	int n;
	while (cin >> n) {
		if (n < 8) {
			cout << "Impossible." << endl;
			continue;
		}

		for(int i = 0 ; i < 4 ;i++){
			int lastPrime = getLastPrime(n,primes,6-(i*2));
			cout << lastPrime <<" ";
			n-=lastPrime;
		}
		cout << endl;
	}

	return 0;
}
