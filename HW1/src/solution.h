#include <stdio.h>

const char* names[3] = {"Car", "Bus", "Truck"};

struct Car {
  short speed;
};

struct Bus {
  short passangers;
};

struct Truck {
  int weight;
};

struct Auto {
	int fuel_capacity;
	double fuel_spending;

	enum Type {
    CAR = 1,
    BUS = 2,
    TRUCK = 3
  } transport;

	union {
		Car _car;
		Bus _bus;
		Truck _truck;
	};
};

struct Container {
  Auto* array;
  size_t size;
};

void input(Auto& object);

void output(const Auto& object);

double calculateDistance(const Auto& object);

bool compare(const Auto& lhs, const Auto& rhs);

void inclusionSort(Container& container);