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
        virtual ~figure(){};
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
        double perimeter(void) const;
        double square(void) const;
        void info(void) const;
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
        double perimeter(void) const;
        double square(void) const;
        void info(void) const;
    private:
        double _sideA = 0;
        double _sideB = 0;
        double _sideC = 0;
};

void scan_triangle(istream &cin, int count_figurs, int p_menu, figure **data);
void scan_circle(istream &cin, int count_figurs, int p_menu, figure **data);

#endif //__FIGURE__H__
