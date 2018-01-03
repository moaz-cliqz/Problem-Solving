//============================================================================
// Name        : uva_128-Software.cpp
// Author      : Moaz Rashad
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
#define g 34943


int main() {
	string inputLine;
	while (getline(cin, inputLine)) {
		unsigned long message = 0;

		if (inputLine[0] == '#')
			break;

		for (int i = 0; i < inputLine.size(); i++) {
			message <<= 8;
			message += inputLine[i];
			message %= g;
		}
		message <<= 16;
		message %= g;

		int CRC = (g - message) % g;

		printf("%02X %02X\n", CRC >> 8, CRC % 256);
	}
	return 0;
}
