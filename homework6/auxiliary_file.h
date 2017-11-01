#ifndef __AUXILIARY_FILE__H__
#define __AUXILIARY_FILE__H__

#include <iostream>
#include <fstream>
#include <stdarg.h>

using namespace std;

void correct_input_double(istream &cin, int num, ...);
void correct_input_int(istream &cin, int num, ...);

#endif //__AUXILIARY_FILE__H__