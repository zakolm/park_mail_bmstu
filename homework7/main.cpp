#include <iostream>

#include "constant.h"
#include "vector.h"

using namespace std;

int main(void)
{
    try
    {
        cout << "Введите кол-во векторов: ";
        int count_vectors = 0;
        cin >> count_vectors;
        Vector<int> *v = new Vector<int>[count_vectors];
        for (int i = 0; i < count_vectors; ++i)
        {
            cout << "Введите размер " << i + 1 << " вектора: ";
            int count_el = 0;
            cin >> count_el;
            v[i] = Vector<int>(count_el);
        }

        //cout << count_vectors;
        for (int i = 0; i < count_vectors; ++i)
        {
            //cout << i << endl;
            cout << "Введите координаты " << i + 1 << " вектора: ";
            //cout << v[i] << endl;
            //cout << v[i].GetSize() << endl;
            cin >> v[i];
            //cout << i << endl;
        }
        
        cout << "Вывод векторов с их длиннами:" << endl;
        for (int i = 0; i < count_vectors; ++i)
        {
            cout << "вектор " << i+1 << ": " << v[i] << endl;
            cout << "длина: " << v[i].len() << endl;
        }
        
        cout << "Попарно сравниваем вектора:" << endl;
        for (int i = 0; i < count_vectors/2; ++i)
        {
            for (int j = count_vectors/2 + count_vectors%2; j < count_vectors; ++j)
            {
                cout << "Вектора " << i + 1 << " и " << j + 1 << endl;
                orto(*v, *(v+1));
                col(*v, *(v+1));
                cout << endl;
            }
        }
            
        cout << (*v)++ << endl;
        cout << *v << endl;
        cout << ++(*(v)) << endl;
        //Vector<int>v3(v);
        //cout << v3 << endl << ++v3;*/
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
            cerr << "\n\n" << "MultiplyError: Can not multiply these vectors" << endl;
        }
        else if (error == ERROR_ADDITION)
        {
            cerr << "\n\n" << "AdditionError: Can not add these vectors" << endl;
        }
    }
    catch(...)
    {
        cerr << "\n\n" << "Something else" << endl;
    }

	return OK;
}
