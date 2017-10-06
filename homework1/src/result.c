#include "result.h"

void clear(const int count, char* word) {
	int i = 0;
	for ( ; i <= count; ++i )
		*(word+i) = 0;
}

int compare(const void* first_item, const void* second_item) {
	return ( *(char*)second_item - *(char*)first_item );
}

int mediana(const int count, const int* array ) {
	int result;
	if (count%2) {
		result = *(array+(count/2-1));
	} else {
		result = *(array+(count/2));
	}
	return result;
}
