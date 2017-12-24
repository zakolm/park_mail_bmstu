#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool IsPalindrom(const string& word) {
	bool result = true;

	for ( int i = 0; i < (int)(word.size() / 2); ++i ) {
		if ( word[i] != word[word.size() - i - 1] ) {
			result = false;
			break;
		}
	}

	return result;
}

int main() {
	ifstream input("palindrom.txt");

	int count_words_palindrom = 0;//vector<string> words_palindrom;
	if ( input ) {
		string word;
		while ( input >> word ) {
			if ( IsPalindrom(word) )
				count_words_palindrom++;//words_palindrom.push_back(word);
		}
	}
	/* если нужен массив для вывода всех палиндромов.
	for ( auto item : words_palindrom ) {
		cout << item << endl;
	}
	*/
	cout << count_words_palindrom;

	return 0;
}
