#include <iostream>
#include <fstream>
#include <stdarg.h>

#include "figure.h"
#include "auxiliary_file.h"
#include "CONSTANT.h"

using namespace std;

/*
* Реализовать абстрактный базовый класс-интерфейс «Плоская фигура», содержащий чисто виртуальные функции:
* * для отображения информации о фигуре.
* * вычисления периметра фигуры.
* * вычисления площади фигуры.
*
* Построить производные классы:(переопределяющие виртуальные функции базового класса.)
* * «Окружность»
* * «Треугольник»
*
* Создать массив указателей на объекты базового класса и заполнить этот массив объектами производных классов.
* Продемонстрировать работу переопределённых методов.
*
*Класс-интерфейс – это класс, содержащий только чисто виртуальные функции.
*/

int menu(istream& cin);

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
