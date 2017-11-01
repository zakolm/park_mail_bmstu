#include <iostream>
#include <fstream>
#include <stdarg.h>

#include "figure.h"

using namespace std;

void correct_input_double(istream &cin, int num, ...);

void correct_input_int(istream &cin, int num, ...);

int menu(istream& cin);

void scan_triangle(istream &cin, int count_figurs, int p_menu, figure **data);

void scan_circle(istream &cin, int count_figurs, int p_menu, figure **data);

int main(void)
{
    int p_menu = menu(cin);
	int count_figurs = 0;
	//stream
	if (!p_menu)
	{
		while (count_figurs <= 0)
		{
			cout << "Введите количество элементов: ";
			correct_input_int(cin, 1, &count_figurs);
		}
	}
	//auto
	else
	{
		count_figurs = FIGURS;
	}
	figure **data = new figure*[count_figurs];
	scan_triangle(cin, count_figurs, p_menu, data);
	scan_circle(cin, count_figurs, p_menu, data);
	// print info about figure
    for (int i = 0; i < count_figurs; ++i)
    {
        data[i]->info();
        if (i < count_figurs - 1)
		{
            cout << endl;
		}
    }
    //clean memory
    for (int i = 0; i < 10; ++i)
    {
        delete data[i];
    }
    delete[] data;
    return OK;
}

int menu(istream& cin)
{
    int p_menu = -1;
    while (p_menu != 0 && p_menu != 1)
	{
        cout << "0 - Вводить все данные самому" << endl;
        cout << "1 - Довериться студенту:)" << endl;
		correct_input_int(cin, 1, &p_menu);
	}
	
	return p_menu;
}

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

void scan_triangle(istream &cin, int count_figurs, int p_menu, figure **data)
{
	if (!p_menu)
	{
		for (int i = 0; i < count_figurs / 2; ++i)
		{
			double sideA = 0;
			double sideB = 0;
			double sideC = 0;
			cout << "Введите стороны " << i+1 <<" треугольника A, B, C: ";
			correct_input_double(cin, 3, &sideA, &sideB, &sideC);
			data[i] = new triangle(sideA, sideB, sideC);
		}
	}
	else
	{
		for (int i = 0; i < count_figurs / 2; ++i)
		{
			data[i] = new triangle(i+1, i+2, i+3);
		}
	}
}

void scan_circle(istream &cin, int count_figurs, int p_menu, figure **data)
{
	if(!p_menu)
	{
		for (int i = count_figurs / 2; i < count_figurs; ++i)
		{
			double radius = 0;
			cout << "Введите радис окружности: ";
			correct_input_double(cin, 1, &radius);
			data[i] = new circle(radius);
		}
	}
	else
	{
		for (int i = count_figurs / 2; i < count_figurs; ++i)
		{
			data[i] = new circle(i);
		}
	}
}