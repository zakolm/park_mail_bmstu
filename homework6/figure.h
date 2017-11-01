#ifndef __FIGURE__H__
#define __FIGURE__H__

#include <iostream>
#include <math.h>

#include "CONSTANT.h"

using namespace std;

class figure
{
    public:
        figure(){};
        ~figure(){};
        virtual void info(void) const = 0;
        virtual double perimeter(void) const = 0;
        virtual double square(void) const = 0;
};

class circle: public figure
{
    public:
        circle(){};
        circle(double radius)
        {
            this->_radius = radius;
        };
        ~circle(){};
        double perimeter(void) const
        {
            return (DOUBLE_PI * this->_radius);
        }
        double square(void) const
        {
            return (TWO_PI * this->_radius);
        }
        void info(void) const
        {
            cout << "CIRCLE" << endl;
            cout << "radius: " << this->_radius  << endl;
            cout << "perimeter: " << perimeter() << endl;
            cout << "square: " << square();
        }
    private:
        double _radius = 0;
};

class triangle: public figure
{
    public:
        triangle(){};
        triangle(double sideA, double sideB, double sideC)
        {
            this->_sideA = sideA;
            this->_sideB = sideB;
            this->_sideC = sideC;
        };
        ~triangle(){};
        double perimeter(void) const
        {
            return (this->_sideA + this->_sideB + this->_sideC);
        }
        double square(void) const
        {
            double half_perimeter = perimeter();
            half_perimeter = half_perimeter / 2;
            double result = 0;
            result = sqrt(half_perimeter * (half_perimeter - this->_sideA) * (half_perimeter - this->_sideB) * (half_perimeter - this->_sideC));
            return result;
        }
        void info() const
        {
            cout << "TRIANGLE" << endl;
            cout << "side A: " << this->_sideA << endl;
            cout << "side B: " << this->_sideB << endl;
            cout << "side C: " << this->_sideC << endl;
            cout << "perimeter: " << perimeter() << endl;
            cout << "square: " << square();
        }
    private:
        double _sideA = 0;
        double _sideB = 0;
        double _sideC = 0;
};

#endif //__FIGURE__H__
