#include <iostream>

#include "constant.h"
#include "vector.h"

using namespace std;

int main(void)
{
    try
    {
        cout << "Введите кол-во векторов: ";
        size_t count_vectors = 0;
        cin >> count_vectors;
        Vector<int> **v = new Vector<int>*[count_vectors];
        for (size_t i = 0; i < count_vectors; ++i)
        {
            cout << "Введите размер " << i + 1 << " вектора: ";
            size_t count_el = 0;
            cin >> count_el;
        Vector<int> *v_tmp = new Vector<int>(count_el);
            cout << "Введите " << count_el << " координаты " << i + 1 << " вектора: ";
        cin >> *v_tmp;
            v[i] = v_tmp;//Vector<int>(count_el);
        }
    
        cout << endl;
        cout << "Вывод векторов с их длиннами:" << endl;
        for (int i = 0; i < count_vectors; ++i)
        {
            cout << "вектор " << i+1 << ": " << *v[i] << endl;
            cout << "длина: " << (*v[i]).len() << endl;
        }
       
        cout << endl;
        cout << "Демонстрация инкремента и декремента: " << endl;
        cout << "Изначальный вектор: " << **v << endl;  
        cout << "Увеличим вектор(инкремент): " << (**v)++ << endl;
        cout << "Получившийся вектор: " << **v << endl;
        cout << "Увеличим вектор(декремент теперь)" << ++(**(v)) << endl;
        cout << "Уменьшим вектор(инкремент): " << (**v)-- << endl;
        cout << "Получившийся вектор: " << **v << endl;
        cout << "Уменьшим вектор(декремент теперь)" << --(**(v)) << endl;

        cout << endl;
        cout << "Демонстрация индексирования: " << endl;
        cout << "Изначальный вектор: " << **v << endl;
        cout << "Первый эл-нт: " << (**v)[0] << endl;
        cout << "Последний эл-нт: " << (**v)[(**v).GetSize()-1] << endl;
        
        cout << endl;
        cout << "Демонстрация сложения и вычитания векторов: " << endl;
        cout << "Вектор a = {" << **v << "}\n" << "Сложим с\nВектором b = {" << (**(v+1)) << "}" << endl;
        cout << "Получим вектор c = {" << ((**v) + (**(v+1))) << "}" << endl;
        cout << "Вычтем из\nВектора a = {" << **v << "}\nВектор b = {" << (**(v+1)) << "}" << endl;
        cout << "Получим вектор c = {" << ((**v) - (**(v+1))) << "}" << endl;
        
        cout << endl;
        cout << "Демонстрация умножения вектора на число: " << endl;
        cout << "Изначальный вектор: " << **v << endl;
        cout << "Умножим на 2: " << (**v) * 2 << endl;
    
        cout << endl;   
        cout << "Попарно сравниваем вектора:" << endl;
        for (int i = 0; i < (count_vectors / 2 + count_vectors % 2); ++i)
        {
            for (int j = i + 1; j < count_vectors; ++j)
            {
                cout << "Вектора " << i + 1 << " и " << j + 1 << endl;
                orto(**(v + i), **(v + j));
                col(**(v + i), **(v + j));
                cout << endl;
            }
        }
    delete[] v;
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
        if (error == ERROR_MULTIPLY)
        {
            cerr << "\n\n" << "MultiplyError: Can not multiply these vectors or Size vectors is 0" << endl;
        }
        else if (error == ERROR_ADDITION)
        {
            cerr << "\n\n" << "AdditionError: Can not add these vectors" << endl;
        }
        else if (error == ERROR_MINUS)
        {
            cerr << "\n\n" << "MinusError: Can not deduction these vectors" << endl;
        }
    }
    catch(...)
    {
        cerr << "\n\n" << "Unknown error" << endl;
    }

    return OK;
}
