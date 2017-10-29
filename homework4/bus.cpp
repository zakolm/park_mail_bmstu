#include <fstream>

#include "bus.h"

void readFromStream(istream& stream, bus_s* array, int count)
{
	/*
	if (stream != cin)
	{
		return -1;
	}
	*/
	char firstname;
        char *lastname = new char[MAX_SIZE];
        char middlename;
        int bus_number;
        char *route_number = new char[MAX_SIZE];
        char *brand_auto = new char[MAX_SIZE];
        unsigned start_uses_year;
        unsigned mileage_auto;
	
	for (; count; count--, array++)
	{
		cout << "Input info:" << endl;
		
		cout << "last name: ";
		stream >> lastname;
		cout << "first name(first symbol): ";
		stream >> firstname;
		cout << "middle name(first symbol): ";
		stream >> middlename;
		
		cout << "bus number: ";
		stream >> bus_number;

		cout << "route number: ";
		stream >> route_number;

		cout << "brand: ";
		stream >> brand_auto;

		cout << "start uses year: ";
		stream >> start_uses_year;

		cout << "mileage: ";
		stream >> mileage_auto;

		array->SetName(lastname, firstname, middlename);
		array->SetBusNumber(bus_number);
		array->SetRouteNumber(route_number);
		array->SetBrandAuto(brand_auto);
		array->SetStartUsesYear(start_uses_year);
		array->SetMileageAuto(mileage_auto);
	}
	delete[] lastname;
	delete[] route_number;
	delete[] brand_auto;
}

void readFromFile(ifstream &file, bus_s *array, int count_buses)
{
	char *tmp = new char[MAX_SIZE];
	char *lastname = new char[MAX_SIZE];
	char firstname;
	char middlename;
	int bus_number;
	char *route_number = new char[MAX_SIZE];
	char *brand_auto = new char[MAX_SIZE];
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
	delete[] lastname;
	delete[] route_number;
	delete[] brand_auto;
	delete[] tmp;
}
