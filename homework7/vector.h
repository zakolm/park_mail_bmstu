#ifndef __VECTOR__H__
#define __VECTOR__H__

#include <iostream>
#include <fstream>
#include <math.h>

#include "constant.h"

using namespace std;

template <class T> class Vector
{
private:
    size_t _size = 0;
    T* _data = NULL;
public:
    Vector(){};
    Vector(size_t size)
    {
        if (size <= 0)
        {
            throw bad_alloc();
        }
        
        _size = size;
        _data = new T[_size];
        
        if (!_data)
        {
            throw bad_alloc();
        }
    };
    Vector(Vector &cv)
    {
        _size = cv._size;
        _data = new T[_size];
         if (!_data)
        {
            throw bad_alloc();
        }
        //копирование координат
        for(size_t i = 0;i < _size; ++i)
        {
            _data[i]=cv._data[i];
        }
    };
    ~Vector()
    {
        delete[] _data;
    };
    double len(void) const
    {
        double res = 0;
        for (size_t i = 0; i < this->_size; ++i)
        {
            res += (this->_data[i]*this->_data[i]);
        }
        res = sqrt(res);
        return res;
    }
    size_t GetSize(void) const
    {
        return _size;
    }
    T operator*(const Vector<T> &b) const
    {
        if (this->_size != b._size)
        {
            throw ERROR_MULTIPLY;//exit(-1);
        }
        T res = 0;
        for (size_t i = 0; i < this->_size; ++i)
        {
            res += this->_data[i] * b._data[i];
        }
        return res;
    }
    Vector<T> operator*(int l)
    {
        for (size_t i = 0; i < this->_size; ++i)
        {
            this->_data[i] = this->_data[i] * l;
        }
        return *this;
    }
    Vector<T> operator+(const Vector<T> &b) const
    {
        if (this->_size != b._size)
        {
            throw ERROR_ADDITION;
        }
        Vector<T> new_vector(_size);
        for (size_t i = 0; i < this->_size; ++i)
        {
            new_vector._data[i] = this->_data[i] + b._data[i];
        }
        return new_vector;
    }
    Vector<T> operator-(const Vector<T> &b) const
    {
        Vector<T> new_vector(_size);
        for (size_t i = 0; i < this->_size; ++i)
        {
            new_vector._data[i] = this->_data[i] - b._data[i];
        }
        return new_vector;
    }
    Vector<T> operator--(int value)
    {
        Vector<T> res(*this);
        for (size_t i = 0; i < this->_size; ++i)
        {
            this->_data[i]--;
        }
        return res;
    }
    Vector<T> operator--(void)
    {
        for (size_t i = 0; i < this->_size; ++i)
        {
            this->_data[i] = this->_data[i]--;
        }
        return *this;
    }
    T & operator[](size_t i) const
    {
        if (i < _size && i >= 0)
        {
            return _data[i];
        }
        else
        {
            throw out_of_range("ERROR");
        }
        return _data[0];
    }
    friend istream & operator>>(istream &stream, Vector<T> &rs)
    {
        for (size_t i = 0; i < rs._size; i++)
            stream >> rs._data[i];
        return stream;
    }
    friend ostream & operator<<(ostream &stream, const Vector<T> &rs)
    {
        for (size_t i = 0; i < rs._size; ++i)
        {
            stream << rs._data[i];
            if (i != rs._size)
            {
                stream << ' ';
            }
        }
        return stream;
    }
    Vector<T> operator++(int value)
    {
        Vector<T> res(*this);
        for (size_t i = 0; i < this->_size; ++i)
        {
            this->_data[i]++;
        }
        return res;
    }
     Vector<T>& operator++(void)
    {
        for (size_t i = 0; i < this->_size; ++i)
        {
            this->_data[i]++;
        }
        return *this;
    }
};

template <class T>
void orto(Vector<T> &a, Vector<T> &b)
{
    T res = a * b;
    if (res == 0 || fabs(res) <= EPS)
    {
        printf("вектора ортогональны\n");
    }
    else
    {
        printf("вектора не ортогональны\n");
    }
}

template <class T>
void col(Vector<T> &a, Vector<T> &b)
{
    T res = a * b;
    double len1 = fabs(a.len() * b.len());
    if ((len1 == res) || (len1 - res) <= EPS)
    {
        printf("вектора коллинеарны");
    }
    else
    {
        printf("вектора не коллинеарны");
    }
}

#endif //__VECTOR__H__
