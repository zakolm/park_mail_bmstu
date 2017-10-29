#include <stdio.h>
#include <string.h>
#include <fstream>

#include "mystring.h"

using namespace std;

String &String::operator =(const String &NewStr)
{
	if (_size != 0)
	{
		_size = 0;
		delete[] str;
	}
	_size = NewStr._size;
	str = new char[_size];
	snprintf(str, _size, NewStr.str);
	return *this;
}

String String::operator+(const String& AddStr)
{
	String tmp;
	tmp._size = AddStr._size + _size;
	tmp.str = new char[tmp._size];
	snprintf(tmp.str, tmp._size, "%s%s", str, AddStr.str);
	return tmp;
}
String String::operator+(const char* AddStr)
{
	String tmp;
	tmp._size = strlen(AddStr) + _size;
	tmp.str = new char[tmp._size];
	snprintf(tmp.str, tmp._size, "%s%s", str, AddStr);
	return tmp;
}

String &String::operator+=(const char* AddStr)
{
	_size += strlen(AddStr)+1;
	String tmp = *this;
	str = new char[_size];
	snprintf(str, _size, "%s%s", tmp.str, AddStr);
	str[_size-1] = '\0';
	return *this;
}

ostream &operator<<(ostream &stream, const String &str)
{
	stream << str.str;
	return stream;
}

bool operator==(const String& str1, const String& str2)
{
	if (str1._size == str2._size)
	{
		return !strcmp(str1.str, str2.str);
	}

	return false;

}
bool operator!=(const String& str1, const String& str2)
{
	return !(str1 == str2);
}

const char String::operator[](int i) const
{
	if (_size > i && i >= 0)
		return str[i];
	return -1;
}

bool operator>(const String& str1, const String& str2)
{
	return strcmp(str1.str, str2.str) > 0;
}
