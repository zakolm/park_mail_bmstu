#ifndef __BUS__H__
#define __BUS__H__

#include <iostream>
#include <string.h>

using namespace std;

class bus_s
{
public:
	bus_s(){};
	~bus_s(){};

	void SetLastName(char *LastName)
	{
		strcpy(last_name, LastName);
	}
	const char *GetLastName() const
	{
		return last_name;
	}

	void SetFirstName(char FirstName)
	{
		first_name = FirstName;
	}
	char GetFirstName() const
	{
		return first_name;
	}

	void SetMiddleName(char MiddleName)
	{
		middle_name = MiddleName;
	}
	char GetMiddleName() const
	{
		return middle_name;
	}

	void SetName(char* LastName, char FirstName, char MiddleName)//Name new_name)
	{
		//cout << LastName << FirstName << MiddleName << endl;
		SetLastName(LastName);
		SetFirstName(FirstName);
		SetMiddleName(MiddleName);
	}

	void SetBusNumber(int BusNumber)
	{
		bus_number = BusNumber;
	}
	int GetBusNumber() const
	{
		return bus_number;
	}

	void SetRouteNumber(char *RouteNumber)
	{
		strcpy(route_number, RouteNumber);
	}
	const char *GetRouteNumber() const
	{
		return route_number;
	}

	void SetBrandAuto(char *BrandAuto)
	{
		strcpy(brand_auto, BrandAuto);
	}
	const char *GetBrandAuto() const
	{
		return brand_auto;
	}

	void SetStartUsesYear(unsigned StartUsesYear)
	{
		start_uses_year = StartUsesYear;
	}
	unsigned GetStartUsesYear() const
	{
		return start_uses_year;
	}

	void SetMileageAuto(unsigned MileageAuto)
	{
		mileage_auto = MileageAuto;
	}
	unsigned GetMileageAuto() const
	{
		return mileage_auto;
	}

	void Show() const
	{
		cout << "Ф.И.О. водителя: ";
		//cout << GetName();
		cout << GetLastName() << '.' << GetFirstName() << '.' << GetMiddleName();
		cout << '\n';

		cout << "Номер автобуса: ";
		cout << GetBusNumber();
		cout << '\n';

		cout << "Номер маршрута: ";
		cout << GetRouteNumber();
		cout << '\n';

		cout << "Марка автомобиля: ";
		cout << GetBrandAuto();
		cout << '\n';

		cout << "Год начала эксплуатации автомобиля: ";
		cout << GetStartUsesYear();
		cout << '\n';

		cout << "Пробег автомобиля: ";
		cout << GetMileageAuto();
		cout << '\n';
	}

private:
	char last_name[1024];
	char first_name;
	char middle_name;
	int bus_number;
	char route_number[1024];
	char brand_auto[1024];
	unsigned start_uses_year;
	unsigned mileage_auto;
};

void readFromStream(istream& stream, bus_s* array, int count);
void readFromFile(ifstream &file, bus_s* array, int count_buses);

#endif //__BUS__H__
