#include <iostream>
#include <math.h>

#include "figure.h"
#include "auxiliary_file.h"
#include "CONSTANT.h"

using namespace std;

//triangle
double triangle::perimeter(void) const
{
    return (this->_sideA + this->_sideB + this->_sideC);
}

double triangle::square(void) const
{
    double half_perimeter = perimeter();
    half_perimeter = half_perimeter / 2;
    double result = 0;
    result = sqrt(half_perimeter * (half_perimeter - this->_sideA) * (half_perimeter - this->_sideB) * (half_perimeter - this->_sideC));
    return result;
}

void triangle::info(void) const
{
    cout << "TRIANGLE" << endl;
    cout << "side A: " << this->_sideA << endl;
    cout << "side B: " << this->_sideB << endl;
    cout << "side C: " << this->_sideC << endl;
    cout << "perimeter: " << perimeter() << endl;
    cout << "square: " << square();
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
            cout << "Введите стороны " << i + 1 <<" треугольника A, B, C: ";
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

//circle
double circle::perimeter(void) const
{
    return (DOUBLE_PI * this->_radius);
}

double circle::square(void) const
{
    return (TWO_PI * this->_radius);
}

 void circle::info(void) const
{
    cout << "CIRCLE" << endl;
    cout << "radius: " << this->_radius  << endl;
    cout << "perimeter: " << perimeter() << endl;
    cout << "square: " << square();
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