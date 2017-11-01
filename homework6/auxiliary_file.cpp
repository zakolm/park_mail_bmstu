#include <iostream>
#include <fstream>
#include <stdarg.h>

#include "auxiliary_file.h"
#include "figure.h"

using namespace std;

void correct_input_double(istream &cin, int num, ...)
{
    va_list list;
    va_start(list, num);
    double *next;
    while (num--)
    {
        next = va_arg(list, double*);
        *next = 0;
        double tmp;
        while (*next <= 0)
        {
            cin >> tmp;
            if (!cin)
            {
                cin.clear();
                while(cin.get() != '\n');
                cout << "Ошибка ввода" << endl;
                cout << "Введите оставшихся " << num+1 << " элементов: " << endl;
            }
            else
            {
                *next = tmp;
            }
            if (*next < 0)
            {
                cout << "Ошибка ввода" << endl;
                cout << "Введите оставшихся " << num+1 << " элементов: " << endl;
            }
        }
    }
    va_end(list);
}

void correct_input_int(istream &cin, int num, ...)
{
    va_list list;
    va_start(list, num);
    int *next;
    while (num--)
    {
        next = va_arg(list, int*);
        *next = -1;
        int tmp;
        cin >> tmp;
        if (!cin)
        {
            cin.clear();
            while(cin.get() != '\n');
            cout << "Ошибка ввода" << endl;
        }
        else
        {
            *next = tmp;
        }
    }
    va_end(list);
}