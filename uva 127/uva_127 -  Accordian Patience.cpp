//============================================================================
// Name        : uva_127.cpp
// Author      : Moaz Rashad
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main() {

	string in;
	while (cin >> in) {
		if (in[0] == '#')
			break;
		vector<stack<string> > cards;
		stack<string> s;
		s.push(in);
		cards.push_back(s);
		for (int i = 1; i < 52; i++) {
			stack<string> s;
			cin >> in;
			s.push(in);
			cards.push_back(s);
		}

		for (int i = 1; i < cards.size(); i++) {
			if (i >= 3
					&& (cards[i].top()[0] == cards[i - 3].top()[0]
							|| cards[i].top()[1] == cards[i - 3].top()[1])) {
				cards[i - 3].push(cards[i].top());
				cards[i].pop();
				if (cards[i].empty())
					cards.erase(cards.begin() + i, cards.begin() + i + 1);
				i -= 4;
			} else if (i >= 1
					&& (cards[i].top()[0] == cards[i - 1].top()[0]
							|| cards[i].top()[1] == cards[i - 1].top()[1])) {
				cards[i - 1].push(cards[i].top());
				cards[i].pop();
				if (cards[i].empty())
					cards.erase(cards.begin() + i, cards.begin() + i + 1);\
				i -= 2;
			}

		}

		const int size = cards.size();
		cout << size << " pile" << ((size == 1) ? " " : "s ") << "remaining:";
		for (int i = 0; i < size; i++)
			cout << " " << cards[i].size();
		cout << endl;
	}
	return 0;
}

