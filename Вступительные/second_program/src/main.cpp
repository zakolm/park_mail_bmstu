#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	/*
	vector<bool> our_numbers(2147483, false);
	char number;
	while((number = getchar()) != EOF) {
		if( (number >= '0') && (number <= '9') )
			our_numbers[atoi(&number)] = true;
	}
	typedef vector<bool> IntContainer;

	int result = 0;//find(our_numbers.begin(), our_numbers.end(), true);
	if ( find(our_numbers.begin(), our_numbers.end(), true) != our_numbers.end() ) {
		cout << result;
	}
	*/

	typedef vector<bool> IntContainer;
	typedef IntContainer::iterator IntIterator;

	IntContainer our_numbers(2147483, false);

	char number;
	while((number = getchar()) != EOF) {
		if( (number >= '0') && (number <= '9') ) {
			//cout << atoi(&number);
			our_numbers[atoi(&number)] = true;
		}
	}

	IntIterator result = find(our_numbers.begin(), our_numbers.end(), true);

	if (result != our_numbers.end()) {
		cout << *result;
	}

	return 0;
}
