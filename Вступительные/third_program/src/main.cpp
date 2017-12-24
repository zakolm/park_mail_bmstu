#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool check(const set<string> f_words, string word, int size_word) {
	int count = 0;
	bool result = false;
	for ( auto item_set : f_words ) {
		if ( item_set.size() == size_word ) {
			for ( int i = 0; i < size_word; ++i ) {
				if ( tolower(item_set[i]) == tolower(word[i]) ) {
					count++;
				} else {
					break;
				}
			}
		}
	}
	if ( count == size_word )
		result = true;
	return result;
}

int main() {
	ifstream forbidden_text("forbidden.txt");
	ifstream text("text.txt");

	vector<string> all_text;
	set<string> forbidden_words;

	if ( forbidden_text ) {
		string forbidden_word;
		while ( forbidden_text >> forbidden_word )
			if (!check(forbidden_words, forbidden_word, forbidden_word.size()))
				forbidden_words.insert(forbidden_word);
	}

	if ( text ) {
		string word;
		while ( text >> word ) {
			if ( forbidden_words.find(word) != forbidden_words.end() ||
					check(forbidden_words, word, word.size()) )
			{
				all_text.push_back("***");
			} else {
				all_text.push_back(word);
			}
		}
	}

	text.close();
	ofstream text_record("text.txt");

	cout << endl;
	for ( int i = 0; i < all_text.size(); ++i ) {
		text_record << all_text[i];
		if ( i < all_text.size() - 1 )
			text_record << ' ';
	}
	text_record.close();

	return 0;
}
