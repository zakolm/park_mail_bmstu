#ifndef __BUS__H__
#define __BUS__H__

#include <iostream>
#include <string.h>

#define MAX_SIZE 1024

using namespace std;

class bus_s
{
public:
	bus_s(){};
	~bus_s()
	{
		delete[] last_name;
		delete[] route_number;
		delete[] brand_auto;
	};

	void SetLastName(const char *LastName)
	{
		snprintf(last_name, MAX_SIZE, "%s", LastName);
	}
	const char *GetLastName() const
	{
		return last_name;
	}

	void SetFirstName(const char FirstName)
	{
		first_name = FirstName;
	}
	char GetFirstName() const
	{
		return first_name;
	}

	void SetMiddleName(const char MiddleName)
	{
		middle_name = MiddleName;
	}
	char GetMiddleName() const
	{
		return middle_name;
	}

	void SetName(const char* LastName, const char FirstName, const char MiddleName)
	{
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

	void SetRouteNumber(const char *RouteNumber)
	{
		snprintf(route_number, MAX_SIZE, "%s", RouteNumber);
	}
	const char *GetRouteNumber() const
	{
		return route_number;
	}

	void SetBrandAuto(const char *BrandAuto)
	{
		snprintf(brand_auto, MAX_SIZE, "%s", BrandAuto);
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
		cout << "Lastname(Initials): ";
		cout << GetLastName() << ' ' << GetFirstName() << '.' << GetMiddleName();
		cout << endl;

		cout << "Bus number: ";
		cout << GetBusNumber();
		cout << endl;

		cout << "Route: ";
		cout << GetRouteNumber();
		cout << endl;

		cout << "Brand: ";
		cout << GetBrandAuto();
		cout << endl;

		cout << "Year: ";
		cout << GetStartUsesYear();
		cout << endl;

		cout << "Mileage: ";
		cout << GetMileageAuto();
		cout << endl;
	}

private:
	char *last_name = new char[1024];
	char first_name;
	char middle_name;
	int bus_number;
	char *route_number = new char[1024];
	char *brand_auto = new char[1024];
	unsigned start_uses_year;
	unsigned mileage_auto;
};

void readFromStream(istream& stream, bus_s* array, int count);
void readFromFile(ifstream &file, bus_s* array, int count_buses);

#endif //__BUS__H__
