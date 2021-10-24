#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

int gen1() {
  return abs(rand() % 100);
}

int gen2() {
  return abs(rand() % 3) + 1;
}

double gen3() {
  return fabs(rand() * 10) / fabs(rand() + 1);
}

int main() {
  for (int test = 1; test <= 3; test++) {
    std::string dir = "test-suits/generated/";
    std::string filename = "test" + std::to_string(test) + ".txt";
    std::ofstream output;
    output.open(dir + filename, std::ios::out);

    int len = abs(rand() % 10 + 1);
    for (int mn = 0; mn < test; mn++) {
      len *= 10;
    }

    output << len << std::endl;
    for (size_t i = 0; i < len; i++) {
      output << gen1() << ' ';
      output << gen3() << ' ';
      output << gen2() << ' ';
      output << gen1() << '\n';
    }

    output.close();
  }
  return 0;
}