#include "./solution.h"

const char* names[3] = {"Car", "Bus", "Truck"};

void Auto::printFuelCapacity(std::ofstream& output) const {
  output << fuel_capacity_ << ' ';
}

void Auto::printFuelSpending(std::ofstream& output) const {
  output << fuel_spending_ << ' ';
}

double Auto::calculateDistance() const {
  double fc = static_cast<double>(fuel_capacity_);
  double fs = static_cast<double>(fuel_spending_);
  return 100.0 * fc / fs;
}

AutoId Auto::getTransport() const {
  return transport_;
}

void Auto::printOwnValue(std::ofstream& output) const {
  output << "Parent class object" << std::endl;
}

void InteractiveController::input(std::ifstream& input, Container& container) {
  int count;
  input >> count;

  container.array.resize(count);
  container.size = count;

  for (size_t item = 0; item < count; item++) {
    int value_type;
    int fuel_capacity;
    double fuel_spending;

    input >> fuel_capacity;
    input >> fuel_spending;
    input >> value_type;

    switch (value_type) {
      case 1: {
        short speed;
        input >> speed;
        container.array[item] = new Car(fuel_capacity, fuel_spending, speed);
        break;
      }
      case 2: {
        short passangers;
        input >> passangers;
        container.array[item] = new Bus(fuel_capacity, fuel_spending, passangers);
        break;
      }
      case 3: {
        int weight;
        input >> weight;
        container.array[item] = new Truck(fuel_capacity, fuel_spending, weight);
        break;
      }
      default: {
        printf("wrong type of tansport\n");
      }
    }
  }
}

void InteractiveController::output(std::ofstream& output, const Container& container) {
  for (size_t item = 0; item < container.size; item++) {
    output << names[container.array[item]->getTransport()];
    output << "maxDistance = ";
    output << container.array[item]->calculateDistance();
  }
}

bool sorting::compare(Auto* lhs, Auto* rhs) {
  return lhs->calculateDistance() < rhs->calculateDistance();
}

void sorting::swap(Auto*& l, Auto*& r) {
  Auto* current = l;
  l = r;
  r = current;
}

void sorting::inclusionSort(Container& container) {
  for (size_t i = 1; i < container.size; i++) {
    for (size_t j = i; j > 0 && compare(container.array[j], container.array[j - 1]); j--) {
      sorting::swap(container.array[j], container.array[j - 1]);
    }
  }
}
