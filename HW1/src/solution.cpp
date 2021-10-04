#include "./solution.h"

void input(Auto& object) {
  int fuel_capacity;
  double fuel_spending;
  int value_type;
  scanf("%d %lf %d ", &fuel_capacity, &fuel_spending, &value_type);
  switch (value_type) {
    case 1: {
      object.transport = Auto::Type::CAR;
      scanf("%d\n", object._car.speed);
      break;
    }
    case 2: {
      object.transport = Auto::Type::BUS;
      scanf("%d\n", object._bus.passangers);
      break;
    }
    case 3: {
      object.transport = Auto::Type::TRUCK;
      scanf("%d\n", object._truck.weight);
      break;
    }
    default: {
      printf("wrong type of tansport\n");
    }
  }
}

void output(const Auto& object) {
  printf(
    "%s maxDistance = %lf\n", 
    names[object.transport],
    calculateDistance(object)
  );
}

double calculateDistance(const Auto& object) {
  double fc = static_cast<double>(object.fuel_capacity);
  double fs = static_cast<double>(object.fuel_spending);
  return 100.0 * fc / fs;
}

bool compare(const Auto& lhs, const Auto& rhs) {
  return calculateDistance(lhs) < calculateDistance(rhs);
}

void inclusionSort(Container& container) {
  for (size_t i = 1; i < container.size; i++) {
    for (size_t j = i; j > 0 && compare(container.array[j], container.array[j - 1]); j--) {
      std::swap(container.array[j], container.array[j - 1]);
    }
  }
}
