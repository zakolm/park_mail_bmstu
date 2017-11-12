#include <iostream>
#include <stdarg.h>

#include "constant.h"
#include "vector.h"

using namespace std;

template <class T>
void clean_all(size_t count_vectors, Vector<T> **v, int num, ...)
{
    for (size_t i = 0; i < count_vectors; ++i)
    {
        delete *(v + i);
    }
    delete[] v;
    va_list list;
    va_start(list, num);
    size_t *next;
    while (num--)
    {
        next = va_arg(list, size_t*);
        delete[] next;
    }
    va_end(list);
}

template <class T>
void input_vectors(size_t count_vectors, Vector<T> **v, size_t *pa)
{
    for (size_t i = 0; i < count_vectors; ++i)
    {
        cout << "Введите размер " << i + 1 << " вектора: ";
        size_t count_el = 0;
        cin >> count_el;
        if (!cin || !count_el)
        {
            clean_all(0, v, 1, pa);
            throw ERROR_INPUT;
        }
        *(pa + i) = count_el;
    }
    
    for (size_t i = 0; i < count_vectors; ++i)
    {
        Vector<T> *v_tmp = new Vector<T>(*(pa + i));
        if (!pa)
        {
            clean_all(i - 1, v, 1, pa);
            throw bad_alloc();
        }
        cout << "Введите " << *(pa + i) << " координаты " << i + 1 << " вектора: ";
        cin >> *v_tmp;
        if (!cin)
        {
            clean_all(i, v, 1, pa);
            throw ERROR_INPUT;
        }
        v[i] = v_tmp;//Vector<int>(count_el);
    }
}

template <class T>
void all_vectors(size_t count_vectors, Vector<T> **v)
{
    cout << endl;
    cout << "Вывод векторов с их длиннами:" << endl;
    for (size_t i = 0; i < count_vectors; ++i)
    {
        cout << "вектор " << i + 1 << ": " << *v[i] << endl;
        cout << "длина: " << (*v[i]).len() << endl;
    }
}

template <class T>
void demo_inc_dec(Vector<T> **v)
{
    cout << endl;
    cout << "Демонстрация инкремента и декремента: " << endl;
    cout << "Изначальный вектор: " << **v << endl;  
    cout << "Увеличим вектор(инкремент): " << (**v)++ << endl;
    cout << "Получившийся вектор: " << **v << endl;
    cout << "Увеличим вектор(декремент теперь)" << ++(**(v)) << endl;
    cout << "Уменьшим вектор(инкремент): " << (**v)-- << endl;
    cout << "Получившийся вектор: " << **v << endl;
    cout << "Уменьшим вектор(декремент теперь)" << --(**(v)) << endl;
}

template <class T>
void demo_index(size_t count_vectors, Vector<T> **v, size_t *pa)
{
    cout << endl;
    cout << "Демонстрация индексирования: " << endl;
    bool flag = true;
    for (size_t i = 0; i < count_vectors; ++i)
    {
        if (*(pa + i) > 1)
        {
            cout << "Изначальный вектор: " << *v[i] << endl;
            cout << "Первый эл-нт: " << (*v[i])[0] << endl;
            cout << "Последний эл-нт: " << (*v[i])[*(pa + i) - 1] << endl;
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "Нет вектора размера больше чем 1, невозможно показать индексирование." << endl;
    }
}

template <class T>
void demo_add_minus_vectors(size_t count_vectors, Vector<T> **v, const size_t *pa, size_t *index_i, size_t *index_j, size_t *count)
{
    *count = 0;
    cout << endl;
    cout << "Демонстрация сложения и вычитания векторов: " << endl;
    for (size_t i = 0; i < count_vectors / 2 + count_vectors % 2; ++i)
    {
        for (size_t j = i + 1; j < count_vectors; ++j)
        {
            if (*(pa + i) == *(pa + j))
            {
                cout << "Вектор a = {" << **(v + i) << "}\n" << "Сложим с\nВектором b = {" << **(v + j) << "}" << endl;
                cout << "Получим вектор c = {" << ((**(v + i)) + (**(v + j))) << "}" << endl;
                cout << "Вычтем из\nВектора a = {" << **(v + i) << "}\nВектор b = {" << **(v + j) << "}" << endl;
                cout << "Получим вектор c = {" << ((**(v + i)) - (**(v + j))) << "}" << endl;
                *(index_i + *count) = i; *(index_j + *count) = j;
                (*count)++;
                cout << endl;
            }
        }
    }
    if (!count)
    {
        cout << "Нет векторов одинаковых размеров, невозможно показать операции сложения и вычитания." << endl;
    }
}

template <class T>
void demo_mult_VectConst(Vector<T> **v)
{
    cout << endl;
    cout << "Демонстрация умножения вектора на число: " << endl;
    cout << "Изначальный вектор: " << **v << endl;
    cout << "Умножим на 2: " << (**v) * 2 << endl;
}

template <class T>
void demo_diff_vectors(Vector<T> **v, size_t count, size_t *index_i, size_t *index_j)
{
    cout << endl;   
    cout << "Попарно сравниваем вектора:" << endl;
    if (count)
    {
        for (size_t i = 0; i < count; ++i)
        {
            cout << "Вектора " << index_i[i] + 1 << " и " << index_j[i] + 1 << endl;
            orto(**(v + index_i[i]), **(v + index_j[i]));
            col(**(v + index_i[i]), **(v + index_j[i]));
            cout << endl;
        }
    }
    else
    {
        cout << "Нет векторов одинаковых размеров, невозможно сравнить вектора." << endl;
    }
}

int main(void)
{
    try
    {
        cout << "Введите кол-во векторов: ";
        size_t count_vectors = 0;
        cin >> count_vectors;
        if (!cin || count_vectors <= 0)
        {
            throw ERROR_INPUT;
        }
        Vector<int> **v = new Vector<int>*[count_vectors];
        if (!v)
        {
            throw bad_alloc();
        }
        size_t *pa = new size_t[count_vectors];
        if (!pa)
        {
            clean_all(0, v, 0);//delete[] v;
            throw bad_alloc();
        }
        
        input_vectors(count_vectors, v, pa);
        
        all_vectors(count_vectors, v);
       
        demo_inc_dec(v);

        demo_index(count_vectors, v, pa);
        
        size_t *index_i = new size_t[count_vectors];
        if (!index_i)
        {
            clean_all(count_vectors, v, 1, pa);
            throw bad_alloc();
        }
        size_t *index_j = new size_t[count_vectors];
        if (!index_j)
        {
            clean_all(count_vectors, v, 2, pa, index_i);
            throw bad_alloc();
        }
        size_t count = 0;
        demo_add_minus_vectors(count_vectors, v, pa, index_i, index_j, &count);
        
        demo_mult_VectConst(v);
    
        demo_diff_vectors(v, count, index_i, index_j);
        
        clean_all(count_vectors, v, 3, pa, index_i, index_j);
    }
    catch(const out_of_range& error)
    {
        cerr << "\n\n" <<"IndexError: list index out of range" << endl;
    }
    catch(const bad_alloc)
    {
        cerr << "\n\n" << "MemoryError: Can not memory allocate" << endl;
    }
    catch(const int& error)
    {
        if (error == ERROR_INPUT)
        {
            cerr << "\n\n" << "SizeError: Can not use this size" << endl;
        }
        else
        {
            cerr << "\n\n" << "Unknown error" << endl;
        }
    }
    catch(...)
    {
        cerr << "\n\n" << "Unknown error" << endl;
    }

    return OK;
}
