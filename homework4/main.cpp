#include <iostream>
#include <string.h>
#include <fstream>
#include <functional>

#include "bus.h"
#include "CONSTANT.h"

using namespace std;


/*
* ¿¿¿¿¿¿¿¿¿¿¿ ¿¿¿¿¿¿ ¿¿¿ ¿¿¿¿¿¿¿¿¿ ¿¿¿¿ ¿¿¿¿¿¿¿¿. ¿¿¿¿¿¿¿¿ ¿ ¿¿¿¿¿ ¿¿¿¿¿¿¿¿¿¿¿¿, ¿¿¿¿¿¿¿¿¿¿¿ ¿¿¿¿¿¿¿¿¿¿¿,
* ¿¿¿¿¿¿¿¿¿¿, ¿¿¿¿¿¿ set(...), get(...), show(...). ¿¿¿¿¿¿ ¿¿¿ ¿¿¿¿¿¿¿¿¿ ¿¿¿¿ ¿¿¿¿¿¿¿¿¿¿ ¿¿¿¿¿¿¿¿ ¿¿¿¿¿¿¿¿¿¿¿.
* ¿¿¿¿¿¿¿¿¿¿ ¿¿¿¿¿¿ ¿¿¿¿¿¿¿¿¿¿¿ ¿¿¿¿¿¿.
*
* Bus:
**  ¿¿¿¿¿¿¿ ¿ ¿¿¿¿¿¿¿¿ ¿¿¿¿¿¿¿¿
**  ¿¿¿¿¿ ¿¿¿¿¿¿¿¿
**  ¿¿¿¿¿ ¿¿¿¿¿¿¿¿
**  ¿¿¿¿¿
**  ¿¿¿ ¿¿¿¿¿¿ ¿¿¿¿¿¿¿¿¿¿¿¿
**  ¿¿¿¿¿¿
*
* ¿¿¿¿¿¿¿ ¿¿¿¿¿¿ ¿¿¿¿¿¿¿¿. ¿¿¿¿¿¿¿:
**  ¿¿¿¿¿¿ ¿¿¿¿¿¿¿¿¿ ¿¿¿ ¿¿¿¿¿¿¿¿¿ ¿¿¿¿¿¿ ¿¿¿¿¿¿¿¿;
**  ¿¿¿¿¿¿ ¿¿¿¿¿¿¿¿¿, ¿¿¿¿¿¿¿ ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿ ¿¿¿¿¿¿ 10 ¿¿¿;
**  ¿¿¿¿¿¿ ¿¿¿¿¿¿¿¿¿, ¿¿¿¿¿¿ ¿ ¿¿¿¿¿¿¿ ¿¿¿¿¿¿ 10 000 ¿¿.
*/

void ShowParam(bus_s *bus, int count, const function<bool(const bus_s*)>& filter = NULL)
{
        bool flag = true;
        for (int i = 0; i < count; ++i, ++bus)
        {
                if (filter(bus))
                {
                        cout << "- ";
                        bus->Show();
                        cout << '\n';
                        flag = false;
                }
        }

        if (flag)
        {
                cout << " [ Empty list ]\n";
        }
}


void print_error(int rc);

int main()
{
	int rc = OK;
	int flag = -1;
	while(flag!=0 && flag!=1)
	{
		cout << "0-stream\n1-file\n: ";
		cin >> flag;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	bus_s* buses;
	int count = 0;
	if (flag)
	{
		cout << "Input file name: ";
		char *filename = new char[1024];
		cin >> filename;
		ifstream file(filename);

		if (file.is_open())
		{
			char *tmp = new char[1024];
			file >> tmp;
			count = atoi(tmp);
			buses = new bus_s[count];

			if (count != 0)
				readFromFile(file, buses, count);

			delete[] tmp;
		}
		else
		{
			count = -1;
			rc = FILE_ERROR;
		}

		delete[] filename;
		file.close();
	}
	else
	{
		cout << "Enter amount of buses: ";
		cin >> count;
		if (count)
			buses = new bus_s[count];
		readFromStream(cin, buses, count);
	}

	if (!count)
	{
		rc = INPUT_ERROR;
	}
	else if (count > 0)
	{
		cout << "-----------------------------------------------------" << endl;
		cout << "All list:" << endl << endl;
		for (int i = 0; i < count; ++i)
		{
			(*(buses+i)).Show();
			cout << endl;
		}

		cout << "-----------------------------------------------------" << endl;
		char Route[] = "M38";
		cout << "Search by route " << Route << ":"  << endl << endl;
		ShowParam(buses, count, [Route](const bus_s* bus)->bool{
			return (!strcmp(bus->GetRouteNumber(), Route));
		});

		cout << "-----------------------------------------------------" << endl;
		cout << "More than 10 years of use:" << endl << endl;
		unsigned MinYearsUses = 10;
		ShowParam(buses, count, [MinYearsUses](const bus_s* bus)->bool{
			return ((2017-bus->GetStartUsesYear()) >= MinYearsUses);
		});

		cout << "-----------------------------------------------------" << endl;
		cout << "The mileage is more than 10 000 km:" << endl << endl;
		unsigned MinMileage = 10000;
		ShowParam(buses, count, [MinMileage](const bus_s* bus)->bool{
			return (bus->GetMileageAuto() > MinMileage);
		});

		delete[] buses;
	}

	print_error(rc);
	return rc;
}

void print_error(int rc)
{
        if (rc == FILE_ERROR)
        {
                cout << "ERROR with FILE" << endl;
        }
        else if (rc == INPUT_ERROR)
        {
                cout << "I/O ERROR" << endl;
        }
}

