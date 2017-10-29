#include <iostream>

#include "mystring.h"

using namespace std;
int compare(const void *str1, const void *str2)
{
    return (*(String*)str1 > *(String*)str2);
}

int main()
{
	String mystr1 = "Cat";
	String mystr2;
	mystr2 = "Hello";

	if (mystr1 != mystr2)
	{
		cout << "What?!" << endl;
		mystr1 = mystr2;
	}
	else
	{
		cout << "Everything is great" << endl;
	}

	if (mystr1 == mystr2)
	{
		cout << "Everything is great" << endl;
	}
	else
	{
		cout << "What?!" << endl;
	}
	cout << mystr1 << endl;
	cout << mystr2 << endl;

	mystr2 += " world!";
	cout << mystr2 << endl;

	String words[10] = {"Man1", "Man2", "Man3", "Man4", "Man5", "Man6", "Man7", "Man8", "Man9", "Man10"};

	qsort(words, 10, sizeof(String), compare);

	for(int i = 0; i < 10; ++i)
	{
		cout << words[i] << endl;
	}


	return 0;
}
