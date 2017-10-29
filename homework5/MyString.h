#ifndef __MYSTRING__H__
#define __MYSTRING__H__

#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class String
{
private:
	char *str = NULL;
	int _size = 0;
public:
	String()
	{
		_size = 0;
		str = NULL;
	}

	String(const char* NewStr)
	{
		_size = strlen(NewStr)+1;
		str = new char[_size];
		snprintf(str, _size, "%s", NewStr);
		str[_size-1] = '\0';
	}

	~String()
	{
		delete[] str;
		_size = 0;
	}
	String &operator=(const String&);
	friend ostream& operator<<(ostream&, const String&);
	String operator+(const String&);
	String operator+(const char*);
	String &operator+=(const char*);
	friend bool operator==(const String&, const String&);
	friend bool operator!=(const String&, const String&);
	const char operator[](int i) const;
	friend bool operator>(const String&, const String&);
};

#endif //__MYSTRING__H__
