#include <fstream>

#include "bus.h"

void readFromStream(istream& stream, bus_s* array, int count)
{
	for (int i = 0; i < count; i++, array++)
	{
		cout << "Enter customer (first name, last name, middle name, ";
		cout << "bus number, route number, brand auto, start uses year, mileage auto):\n";

		char firstname;
		char lastname[1024];
		char middlename;
		int bus_number;
		char route_number[1024];
		char brand_auto[1024];
		unsigned start_uses_year;
		unsigned mileage_auto;

		stream >> lastname >> firstname >> middlename;

		stream >> bus_number >> route_number >> brand_auto;

		stream >> start_uses_year >> mileage_auto;

		array->SetName(lastname, firstname, middlename);
		array->SetBusNumber(bus_number);
		array->SetRouteNumber(route_number);
		array->SetBrandAuto(brand_auto);
		array->SetStartUsesYear(start_uses_year);
		array->SetMileageAuto(mileage_auto);
	}
}

void readFromFile(ifstream &file, bus_s *array, int count_buses)
{
	char *tmp = new char;
	char *lastname = new char;
	char firstname;
	char middlename;
	int bus_number;
	char *route_number = new char;
	char *brand_auto = new char;
	unsigned start_uses_year;
	unsigned mileage_auto;

	for (int i = 0; i < count_buses; i++, array++)
	{
		file >> lastname >> firstname >> middlename;

		file >> tmp;
		bus_number = atoi(tmp);

		file >> route_number >> brand_auto;

		file >> tmp;
		start_uses_year = atoi(tmp);

		file >> tmp;
		mileage_auto = atoi(tmp);

		array->SetName(lastname, firstname, middlename);
		array->SetBusNumber(bus_number);
		array->SetRouteNumber(route_number);
		array->SetBrandAuto(brand_auto);
		array->SetStartUsesYear(start_uses_year);
		array->SetMileageAuto(mileage_auto);
	}
	delete lastname;
	delete route_number;
	delete brand_auto;
	delete tmp;
}
